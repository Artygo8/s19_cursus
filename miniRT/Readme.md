# MiniRT
MiniRT is a mini C RayTracer based on the mini graphic library "minilibx" furnished by the 42 network.


## Usage
MiniRayTracer working on linux and MacOS.

One line test:
```bash
git clone https://github.com/Artygo8/s19_miniRT.git && cd s19_miniRT && make run
```
or
```bash
name@name-PC:~/s19_miniRT$ make
name@name-PC:~/s19_miniRT$ ./miniRT scenes/nine_spheres.rt
```
For more informations about how to setup the minilibx: go to [minilibx_linux](https://github.com/Artygo8/s19_minilibx_linux).
## Scenes
The '.rt' files are describing a scene as such:
```
R		800 800
A		0.25									255,255,255
F		255,255,255

c		0,0,-300			0,0,1		120
l		-150,150,-150					0.2			255,255,0
l		-150,-150,-150					0.2			255,0,0
l		0,0,-150						0.2			255,0,255
l		150,150,-150					0.2			0,0,255
l		150,-150,-150					0.2			0,255,255
l		0,0,400					0.4			255,255,255

sp		0,-90,-45					60				255,255,255
sp		0,90,45					60				255,255,255
sp		-90,0,-45					60				255,255,255
sp		-90,90,0				60				255,255,255
sp		90,-90,0				60				255,255,255
sp		90,0,45					60				255,255,255
sp		90,90,90					60				255,255,255
sp		0,0,0					60				127,127,127
sp		-90,-90,-90				60				0,0,0

pl		0,200,0				0,1,0					255,255,255
pl		0,-200,0			0,1,0					255,255,255
pl		200,0,0				1,0,0					255,255,255
pl		-200,0,0			1,0,0					255,255,255
```
### With
```
R - resolution
A - ambient light
F - filter
c - camera position, orientation, angle
l - point light

sp - sphere
cy - cylinder
pl - plane
sq - plane square
tr - plane triangle
```

### Result
![Nine spheres](screen/nine_spheres.png)

## Update

The project is now working on Catalina. For previous versions, using X11, remove
 the "minilibx" folder and rename the "minilibx_pre_catalina" to "minilibx".
 (This could easily be automated but i didn't do it yet...)

___ edit : version 14 should now be supported ___
