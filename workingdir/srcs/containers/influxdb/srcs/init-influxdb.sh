#!/bin/sh

influxd &
pid="$!"

while true; do
	influx -execute "CREATE USER \"$INFLUXDB_ADMIN_USER\" WITH PASSWORD '$INFLUXDB_ADMIN_PASSWORD' WITH ALL PRIVILEGES" &> /dev/null && break
	sleep 1
done

QUERY="influx -username ${INFLUXDB_ADMIN_USER} -password ${INFLUXDB_ADMIN_PASSWORD} -execute"

# we create db with the credentials : dbname=$svc, dbuser=$svc, dbpassword=$svc
# for name in { "nginx" }; do
# 	$QUERY "CREATE DATABASE $name"
# 	$QUERY "CREATE USER \"$name\" WITH PASSWORD '$name'"
# 	$QUERY "REVOKE ALL PRIVILEGES FROM \"$name\""
# 	$QUERY "GRANT ALL ON \"$name\" TO \"$name\""
# done

kill "$pid"

telegraf &

exec "$@"