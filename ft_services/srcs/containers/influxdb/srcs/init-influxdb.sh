#!/bin/sh

influxd > logs &
pid="$!"

#while [ -z `cat logs | grep "listening for signals"` ]; do
#	sleep 1
#done

sleep 15

influx -execute "CREATE USER \"$INFLUXDB_ADMIN_USER\" IF NOT EXISTS WITH PASSWORD '$INFLUXDB_ADMIN_PASSWORD' WITH ALL PRIVILEGES"

kill $pid
