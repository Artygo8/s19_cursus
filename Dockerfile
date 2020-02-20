FROM debian:buster
COPY ./srcs/scripts/* /
COPY ./srcs/ft_server /var/www/html

RUN bash just_do_it.sh

COPY ./srcs/default /etc/nginx/sites-available/localhost
COPY ./srcs/mkcert/mkcert .

EXPOSE 80 443

#RUN service nginx restart
#RUN service php7.3-fpm restart
#RUN service mysql restart

#CMD nginx -g 'daemon off;'
