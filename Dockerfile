FROM debian:buster
COPY ./srcs/scripts/* /
COPY ./srcs/ft_server /var/www/html

RUN bash 1-*.sh
RUN bash 2-*.sh
#COPY ./srcs/original /etc/nginx/sites-available/default
#COPY ./srcs/original /etc/nginx/sites-enabled/default
#RUN bash 4-*.sh
#RUN bash 5-*.sh
#RUN bash 6-*.sh

EXPOSE 80 443

# Start the LEMP !
RUN service nginx start
#RUN service php7.3-fpm start
#RUN service mysql start
CMD nginx -g 'daemon off;'
