#!/bin/sh

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=root --ldata=/var/lib/mysql
    /usr/bin/mysqld --user=root --bootstrap --verbose=0 < /tmp/query.sql
fi

rm -f /tmp/query.sql

(telegraf; pkill mysqld) &

exec mysqld --user=root --console
