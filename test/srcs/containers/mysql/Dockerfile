FROM alpine:3.12

ARG MYSQL_ROOT_PASSWORD="default"
ARG WP_USER="default"
ARG WP_PASSWORD="default"

RUN apk update && apk upgrade && apk add --update mysql mysql-client

RUN mkdir -p /run/mysqld && touch /run/mysqld/mysqld.sock;\
    chown -R root:root /var/lib/mysql;\
    chown -R root:root /var/lib/mysql;


COPY srcs/query.sql /tmp/query.sql
COPY srcs/my.cnf /etc/mysql/my.cnf
COPY srcs/entrypoint.sh /entrypoint.sh
RUN  chmod +x /entrypoint.sh

VOLUME [ "/var/lib/mysql" ]

RUN sed -i -e "s/MYSQL_ROOT_PASSWORD/$MYSQL_ROOT_PASSWORD/" /tmp/query.sql;\
    sed -i -e "s/WP_PASSWORD/$WP_PASSWORD/" /tmp/query.sql;\
    sed -i -e "s/WP_USER/$WP_USER/" /tmp/query.sql

EXPOSE 3306

ENTRYPOINT [ "sh" , "/entrypoint.sh" ]

CMD ["/usr/bin/mysqld"]
