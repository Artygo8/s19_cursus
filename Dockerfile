FROM debian:buster

COPY ./srcs ./srcs

RUN apt-get update \
	&& apt-get install make \
	&& cd srcs && make
