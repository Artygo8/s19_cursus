# Cleaning
docker image rm debian:buster
docker system prune -f

# Build the image
docker build -t hello:hello .

# Run the image
docker run -it 72b34c405a19 bash

docker build --ssh default .


/var/lib/wordpress#
