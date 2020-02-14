#!/bin/bash
echo -e "\033[42minstalling MySQL\t\t\t\t\033[0m"
#apt install -y default-mysql-server
apt -y install mariadb-server mariadb-client

echo -e "\033[42mMySQL start\t\t\t\t\033[0m"
service mysql start

echo -e "\033[42mMySQL MY_QUERY\t\t\t\t\033[0m"
mysql <<MY_QUERY
FLUSH PRIVILEGES;
ALTER USER root@localhost IDENTIFIED VIA mysql_native_password;
SET PASSWORD = PASSWORD('pwd');
FLUSH PRIVILEGES;
GRANT ALL PRIVILEGES ON phpmyadmin.* TO 'pma'@'localhost' IDENTIFIED BY 'pmapass';
CREATE DATABASE app_db;
GRANT ALL PRIVILEGES ON app_db.* TO 'ADMIN'@'localhost' IDENTIFIED BY 'password';
FLUSH PRIVILEGES;
MY_QUERY
