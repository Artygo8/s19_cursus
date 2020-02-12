#!/bin/bash
mysql -u root -pATATRA <<MY_QUERY
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY 'PPPWD';
GRANT ALL PRIVILEGES ON phpmyadmin.* TO 'pma'@'localhost' IDENTIFIED BY 'pmapass';
CREATE DATABASE app_db;
GRANT ALL PRIVILEGES ON app_db.* TO 'ADMIN'@'localhost' IDENTIFIED BY 'password';
FLUSH PRIVILEGES;
MY_QUERY
