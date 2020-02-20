#!/bin/bash
apt update
apt upgrade -y
apt install -y sudo
apt install -y nginx
apt install -y php7.3-fpm php-curl php-gd php-intl php-mbstring \
	php-soap php-xml php-xmlrpc php-zip php7.3-cli php7.3-mysql php7.3-gd \
	php7.3-imagick php7.3-recode php7.3-tidy php7.3-xmlrpc

chmod -R 755 /var/www/html/*
chown -R www-data:www-data /var/www/html/*

sudo ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/
nginx -t
service nginx start

COPY /srcs/mkcert mkcert
chmod +x ./mkcert
./mkcert -install
./mkcert localhost.com

apt -y install mariadb-server mariadb-client
service mysql start
sudo mysql <<MY_QUERY
CREATE DATABASE wordpress;
GRANT ALL PRIVILEGES ON wordpress.* TO 'root'@'localhost';
FLUSH PRIVILEGES;
update mysql.user set plugin = 'mysql_native_password' where user='root';
MY_QUERY
sudo mysql < /var/www/html/phpmyadmin/sql/create_tables.sql
