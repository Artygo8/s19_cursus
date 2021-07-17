FROM alpine:3.12

RUN echo "@testing http://dl-cdn.alpinelinux.org/alpine/edge/testing" >> /etc/apk/repositories

RUN apk add influxdb telegraf@testing

COPY srcs/init-influxdb.sh /init-influxdb.sh
COPY srcs/influxdb.conf /etc/influxdb/influxdb.conf
COPY srcs/telegraf.conf /etc/telegraf/telegraf.conf

EXPOSE 8086

VOLUME /var/lib/influxdb

RUN /init-influxdb.sh

CMD nohup sh -c "(telegraf;pkill influxd)&";influxd
