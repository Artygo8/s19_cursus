#!/bin/bash
apt -y install mariadb-server
#mariadb-client
service mysql start
mysql <<MY_QUERY
CREATE DATABASE wordpressdb;
CREATE USER 'admin'@'localhost' IDENTIFIED BY 'admin';
GRANT ALL PRIVILEGES ON wordpressdb.* TO 'admin'@'localhost';
FLUSH PRIVILEGES;
MY_QUERY
