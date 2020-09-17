# https://wmartins.github.io/2017/10/creating-a-monitoring-stack-with-docker-swarm-grafana-influxdb-and-telegraf/
FROM alpine:3.12

RUN apk update && apk upgrade && apk add \
    --repository=http://dl-cdn.alpinelinux.org/alpine/edge/testing grafana grafana-openrc openrc
