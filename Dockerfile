FROM debian:buster

COPY ./srcs ./root/

RUN apt-get update \
	&& apt-get install make \
	&& cd root && make
