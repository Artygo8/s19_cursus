FROM alpine:3.11

RUN echo "@testing http://dl-cdn.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories

# Packages
RUN apk update \
    && apk add lighttpd php7-common php7-iconv php7-json php7-gd php7-curl \
    php7-xml php7-mysqli php7-imap php7-cgi fcgi php7-pdo php7-pdo_mysql \
    php7-soap php7-xmlrpc php7-posix php7-mcrypt php7-gettext php7-ldap \
    php7-ctype php7-dom php7 php7-session php7-mbstring telegraf@testing --no-cache

RUN apk add php-mysqli 
RUN apk add mysql-client
RUN apk add mysql

# phpmyadmin
COPY srcs/phpmyadmin/ /var/www/localhost/htdocs
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf

# Lighttpd Config files
RUN sed -i '/include "mod_fastcgi.conf"/s/^#//g' /etc/lighttpd/lighttpd.conf;\
    echo "server.port = 80" >> /etc/lighttpd/lighttpd.conf;\
    sed -i 's/\/usr\/bin\/php-cgi/\/usr\/bin\/php-cgi7/g' /etc/lighttpd/mod_fastcgi.conf

# Directories and permissions for lighttpd
RUN mkdir -p /var/www/localhost/htdocs/stats /var/log/lighttpd /var/lib/lighttpd /var/run/lighttpd;\
    chown -R lighttpd:lighttpd /var/www/localhost/;\
    chown -R lighttpd:lighttpd /var/lib/lighttpd;\
    chown -R lighttpd:lighttpd /var/log/lighttpd;\
    chown -R lighttpd:lighttpd /var/run/lighttpd;

EXPOSE 5000

CMD nohup sh -c "(telegraf; pkill lighttpd) &";lighttpd -D -f /etc/lighttpd/lighttpd.conf
