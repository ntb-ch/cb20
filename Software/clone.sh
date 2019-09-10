#!/bin/bash

script="$(readlink -f $0)"
script_dir="$(dirname $script)"

. "$script_dir/config.sh.in"

if [ ! -d "$eeros_source_dir" ]; then
	git clone $eeros_github_address -o upstream "$eeros_source_dir"
	pushd "$eeros_source_dir"
	git checkout $eeros_github_version
	popd
fi

if [ ! -d "$flink_source_dir" ]; then
	git clone $flinklib_github_address -o upstream --recursive $flink_source_dir
	pushd $flink_source_dir
	git checkout $flinklib_github_version
	popd
fi

if [ ! -d "$flink_eeros_source_dir" ]; then
	git clone $flink_eeros_github_address -o upstream $flink_eeros_source_dir
	pushd $flink_eeros_source_dir
	git checkout $flink_eeros_github_version
	popd
fi

