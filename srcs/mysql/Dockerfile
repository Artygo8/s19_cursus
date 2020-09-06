FROM alpine:3.11

RUN apk add mysql mysql-client
RUN mkdir /var/run/mysqld

COPY srcs/start.sh /tmp/start.sh
COPY srcs/query.sql /tmp/query.sql
COPY srcs/my.cnf /etc/mysql/my.cnf

VOLUME /var/lib/mysql

USER root

EXPOSE 3306

ENTRYPOINT sh /tmp/start.sh
