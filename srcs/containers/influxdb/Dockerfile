FROM alpine:3.12

RUN apk add influxdb

COPY srcs/influxdb.conf /etc/influxdb/influxdb.conf
COPY srcs/init-influxdb.sh /init-influxdb.sh

EXPOSE 8086

VOLUME /var/lib/influxdb

CMD [ "sh", "/init-influxdb.sh" ]