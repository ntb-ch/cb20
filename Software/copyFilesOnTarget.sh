#!/bin/sh

mount / -o remount,rw

cp /tmp/bin/HALConfigExample.json /mnt/data/config
cp -r /tmp/lib /opt/cb20/
cp -r /tmp/bin /opt/cb20/