FROM alpine:3.12

# Packages Lighttpd, openrc, php
RUN apk update \
    && apk add openrc lighttpd php7-common php7-iconv php7-json php7-gd php7-curl \
    php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql \
    php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap \
    php7-ctype php7-dom php7 php7-session --no-cache

# WordPress
COPY srcs/wordpress /var/www/localhost/htdocs/wordpress

# Lighttpd
COPY srcs/lighttpd/lighttpd.conf /etc/lighttpd/lighttpd.conf
COPY srcs/lighttpd/mod_fastcgi.conf /etc/lighttpd/mod_fastcgi.conf

RUN mkdir -p /var/run/lighttpd \
    && touch /var/run/lighttpd/php-fastcgi.socket \
    && chown -R lighttpd:lighttpd /var/run/lighttpd \
    && chown -R lighttpd:lighttpd /var/www/

RUN openrc
RUN touch /run/openrc/softlevel
RUN rc-update add lighttpd default
RUN rc-status

EXPOSE 5050

ENTRYPOINT lighttpd -D -f /etc/lighttpd/lighttpd.conf

CMD openrc
