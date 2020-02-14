FROM debian:buster
COPY ./srcs/scripts/* ./
COPY ./srcs/phpMyAdmin-4.9.0.1-english ./var/www/html/phpmyadmin
COPY ./srcs/index.php ./var/www/html/

RUN bash 1-*.sh
RUN bash 2-*.sh
RUN bash 3-*.sh
COPY ./srcs/default /etc/nginx/sites-enabled/
COPY ./srcs/default /etc/nginx/sites-availables/
RUN bash 4-*.sh
RUN bash 5-*.sh

# Start the LEMP !
CMD service nginx restart
CMD nginx -g 'daemon off;'
