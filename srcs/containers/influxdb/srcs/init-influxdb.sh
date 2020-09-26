#!/bin/sh

influxd > logs &
pid="$!"

while [ -z `cat logs | grep "listening for signals"` ]; do
	sleep 1
done

influx -execute "CREATE USER IF NOT EXISTS \"$INFLUXDB_ADMIN_USER\" WITH PASSWORD '$INFLUXDB_ADMIN_PASSWORD' WITH ALL PRIVILEGES" &> /dev/null

kill "$pid"

influxd

sleep 60 ; exit 1
