FROM debian:buster

COPY ./srcs .

RUN apt-get update \
	&& apt-get install make \
	&& make
