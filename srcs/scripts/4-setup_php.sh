#!/bin/bash
echo -e "\033[42mPhp install\t\t\t\t\033[0m"
	apt install -y php-fpm php-mysql
	service nginx restart
	service php7.3-fpm restart
