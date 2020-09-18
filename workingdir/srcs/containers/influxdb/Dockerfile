FROM alpine:3.12

RUN apk add influxdb

COPY srcs/influxdb.conf /etc/influxdb/influxdb.conf

EXPOSE 8086

VOLUME /var/lib/influxdb

COPY srcs/query.iql /query.iql

CMD ["influxd"]