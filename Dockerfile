FROM debian:buster

COPY ./srcs/wordpress ./var/www/html/wordpress
COPY ./srcs/phpMyAdmin-4.9.0.1-english ./usr/share/phpmyadmin
COPY ./srcs/mysql/mysql_script.sh .

# "L"inux & wordpress
RUN apt-get update
RUN apt-get install -y lsb-release
RUN apt-get install -y sudo

# "E"ngin-x
RUN sudo apt-get remove -y apache2
RUN sudo apt-get install -y nginx
CMD service nginx start

# "M"ySQL
RUN sudo apt-get install -y default-mysql-server
RUN sudo apt-get install mariadb-server mariadb-client
CMD sudo service mysql start

# "P"hp
RUN sudo apt-get install -y php
COPY ./srcs/phpMyAdmin-4.9.0.1-english ./usr/share/phpmyadmin
CMD sudo ln -s /usr/share/phpmyadmin /var/www/html/phpmyadmin
RUN chmod 660 /usr/share/phpmyadmin/config.inc.php
CMD chown -R www-data:www-data /usr/share/phpmyadmin

# REST
#RUN sudo mkdir -p /var/lib/phpmyadmin/tmp
#RUN sudo chown -R www-data:www-data /var/lib/phpmyadmin
#RUN sudo mkdir /etc/phpmyadmin/

#CMD sudo mysql < /usr/share/phpmyadmin/sql/create_tables.sql -u root -pa

#COPY ./srcs/php_config.sh .

CMD bash php_config.sh
CMD bash mysql_script.sh

#COPY ./srcs/phpmyadmin.conf ./etc/nginx/conf.d/

#RUN sudo mkdir /usr/share/phpmyadmin/tmp
#RUN sudo chmod 777 /usr/share/phpmyadmin/tmp
#RUN sudo chown -R www-data:www-data /usr/share/phpmyadmin

EXPOSE 80 443

# Start the LEMP !
COPY ./srcs/index.html ./var/www/html/
CMD service php7.3-fpm start
CMD service nginx restart
CMD nginx -g 'daemon off;'
