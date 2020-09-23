#!/bin/sh

influxd &
pid="$!"

while true; do
	influx -execute "CREATE USER \"$INFLUXDB_ADMIN_USER\" WITH PASSWORD '$INFLUXDB_ADMIN_PASSWORD' WITH ALL PRIVILEGES" &> /dev/null && break
	sleep 1
done

QUERY="influx -username ${INFLUXDB_ADMIN_USER} -password ${INFLUXDB_ADMIN_PASSWORD} -execute"

kill "$pid"

telegraf &

exec "$@"