#!/bin/sh
mysql_install_db
/usr/bin/mysqld < /tmp/query.sql
exec /usr/bin/mysqld --console
