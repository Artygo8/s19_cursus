mysql_install_db --user=root --ldata=/var/lib/mysql
/usr/bin/mysqld --bootstrap --verbose=0 < /tmp/query.sql
exec "$@"
