FROM alpine:3.12

RUN apk update && apk upgrade && apk add --update mysql mysql-client openrc

RUN mkdir -p /run/mysqld && touch /run/mysqld/mysqld.sock
RUN chown mysql /var/lib/mysql

COPY srcs/query.sql /tmp/query.sql
COPY srcs/my.cnf /etc/mysql/my.cnf

RUN mysql_install_db
RUN /usr/bin/mysqld --bootstrap --verbose=0 < /tmp/query.sql

VOLUME /var/lib/mysql

EXPOSE 3306

ENTRYPOINT exec /usr/bin/mysqld
