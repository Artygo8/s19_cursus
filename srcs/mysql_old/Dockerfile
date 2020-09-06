FROM alpine:3.11

USER root

RUN apk update && apk add mysql mysql-client openrc

RUN chown -R mysql:mysql /var/lib/mysql

RUN mkdir /run/mysqld \
    && touch /run/mysqld/mysqld.sock \
    && chown -R mysql:mysql /run/mysqld

RUN openrc && touch /run/openrc/softlevel

RUN mysql_install_db --user=root --datadir=/var/lib/mysql

COPY srcs/my.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY srcs/mysql_query mysql_query


VOLUME ["/var/lib/mysql"]

RUN /usr/bin/mysqld --user=root --bootstrap --verbose=0 < mysql_query;

EXPOSE 3306

ENTRYPOINT exec /usr/bin/mysqld --user=root
