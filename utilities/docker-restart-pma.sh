#!/bin/sh
name="phpmyadmin"

echo "\033[31mdocker stop/rm/rmi $name \033[0m"
docker kill $name 1> /dev/null
docker rm $name 1> /dev/null
docker rmi $name:agossuin -f 1> /dev/null

echo "\033[31mdocker build $name:agossuin \033[0m"
(docker build -t $name:agossuin . 1> /dev/null) || exit

echo "\033[31mdocker run \033[0m"
# docker run --name $name -d -p 443:443 -i $name:agossuin
docker run --name $name -d -i -p 80:80 $name:agossuin || exit
# docker run -it $name:agossuin sh
# docker run -d -p 80:80 $name:agossuin
