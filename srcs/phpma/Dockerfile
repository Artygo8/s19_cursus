FROM alpine:3.11


RUN apk update
RUN apk add lighttpd php7-common php7-iconv php7-json php7-gd php7-curl php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap php7-ctype php7-dom
RUN apk add openrc mysql

RUN echo 'include "mod_fastcgi.conf"' >> /etc/lighttpd/lighttpd.conf
COPY srcs/mod_fastcgi.conf /etc/lighttpd/mod_fastcgi.conf


RUN rc-service lighttpd start && rc-update add lighttpd default




EXPOSE 5000
