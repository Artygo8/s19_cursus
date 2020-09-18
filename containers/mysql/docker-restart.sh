#!/bin/sh
name="mysql"

echo "\033[31mdocker stop/rm/rmi $name \033[0m"
docker kill $name 1> /dev/null
docker rm $name 1> /dev/null
docker rmi $name:$name -f 1> /dev/null

echo "\033[31mdocker build $name:$name \033[0m"
(docker build -t $name:$name . ) || exit

echo "\033[31mdocker run \033[0m"
# docker run --name $name -d -p 443:443 -i $name:$name
docker run --name $name -d -i -p 3306:3306 $name:$name || exit
# docker run -it $name:$name sh
# docker run -d -p 80:80 $name:$name
