# minilibx linux
minilibx tested on ubuntu (mint) and manjaro

## Why?
Some people having difficulties to install the minilibx from the school 42, I modified a version found on [Achedeuzot](https://achedeuzot.me/2014/12/20/installer-la-minilibx/) adding simply by adding a strlcpy.
Now the 
By the way Thank you to [klemen](klemen.server.fr) for those files and explanations !

## How to?
First, let's install OpenGL ! here is the command for debian based versions.
```
sudo apt update
sudo apt install libglu1-mesa-dev freeglut3-dev mesa-common-dev
```

then go inside the minilibx directory and
```
make
```
The installation will raise alot of warnings, it doesn't mean it is not working as long as there are no errors.

To test your installation, use
```
cd ./test
./mlx-test
```
if for some reason, it didnt work the first time, read the error logs and use
```
make re
```
It's important ! 

if like me, you started from a basic OS installation, this commands migh also be useful.
```
sudo apt install build-essential
```

## good luck !
If this is useful to you do not hesitate to let me know with a little star !
You can also contact me by email to agossuin@student.s19.be
