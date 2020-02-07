FROM debian:buster

RUN apt-get update
CMD service nginx restart
RUN apt-get update
RUN apt-get install -y gnupg
RUN apt-get install -y wordpress
RUN apt-get install -y nginx
RUN apt-get install -y php
RUN apt-get install -y php-mysql
CMD nginx -g 'daemon off;'
