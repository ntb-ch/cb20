#!/bin/bash

script="$(readlink -f $0)"
script_dir="$(dirname $script)"

. "$script_dir/config.sh.in"


rm -rf "$build_dir" "$install_dir"

mkdir -p $flink_build_dir
pushd $flink_build_dir
cmake -DCMAKE_TOOLCHAIN_FILE=$toolchain_file -DCMAKE_INSTALL_PREFIX=$install_dir -DCMAKE_BUILD_TYPE=Release $flink_source_dir
make
make install
popd


mkdir -p $eeros_build_dir
pushd $eeros_build_dir
cmake -DCMAKE_TOOLCHAIN_FILE=$toolchain_file -DCMAKE_INSTALL_PREFIX=$install_dir -DCMAKE_BUILD_TYPE=Release $eeros_source_dir
make
make install
popd


mkdir -p $cb20lib_build_dir
pushd $cb20lib_build_dir
cmake -DCMAKE_TOOLCHAIN_FILE=$toolchain_file -DCMAKE_INSTALL_PREFIX=$install_dir -DCMAKE_BUILD_TYPE=Release $cb20lib_source_dir
make
popd


mkdir -p $cb20test_build_dir
pushd $cb20test_build_dir
cmake	-DCMAKE_TOOLCHAIN_FILE=$toolchain_file -DCMAKE_INSTALL_PREFIX=$install_dir \
	-DADDITIONAL_INCLUDE_DIRS="$cb20lib_source_dir/include" \
	-DADDITIONAL_LINK_DIRS="$cb20lib_build_dir" \
	-DCMAKE_BUILD_TYPE=Release \
	$cb20test_source_dir
make
make install
popd

