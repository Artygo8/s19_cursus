if [ ! -d "/var/lib/mysql/mysql" ]; then
    mysql_install_db --user=root --ldata=/var/lib/mysql
fi

/usr/bin/mysqld --user=root --bootstrap --verbose=0 < /tmp/query.sql
rm -f /tmp/query.sql

exec mysqld --user=root --console
