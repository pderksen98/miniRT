# miniRT (Ray Tracer)



<img width="1340" alt="Screen Shot 2022-10-27 at 3 51 45 PM" src="https://user-images.githubusercontent.com/89991397/198308503-ec15fbd8-a7f4-4d02-9611-3e1b50020dc7.png">

## Introduction

During this project we built a basic raytracer in C, where we awere able to render a scene with several objects such as a plane, sphere or cylinder with lights and shadows. We used the MLX42 library in order to render each pixel to the screen. We used the unity unit tester in order to test the parsed data from a .rt file. Concurrency is applied in the form of threading, where 7 threads are used to increase the running time on average of 300% by dividing the computations per pixel. For the computations basic geometry using linear algebra is applied to shoot rays from a window to the objects which are displayed.

## Downloading the Repository

Download the git repo's using the following commands:

```bash
git clone git@github.com:pderksen98/miniRT.git
cd miniRT
```

## Running the program

MLX42 is supported by GLFW. In order to download the GLFW library run the following commands in your command line.
```bash
brew update
brew install glfw
```

Compile the minrRT executable bij running:
```bash
make bonus
```

And execute a map by running a file in the rt_files folder in the command line as an argument of the .rt folder.

```bash
./miniRT rt_files/(can_be_anything).rt
```

## Create your own map

In order to create your own map, create a file with a '.rt' extension.

You must add the following lines (A, C, L):

```bash
A 0.2 255,255,255
C 0,0,-17 0,0,1 110
L 0,0,0 1 255,255,255
```

**'A'** is the ambient light. 
- First digit, in this case 0.2, is the intensity in the range [0, 1]
- Followed by the collor code r,b,g in the range [0, 255]

**'C'** is the campera.
- First 3 digits are the x,y,z coordinates (any real numbers)
- Second 3 digits form the direction where you look at: normalized orientation vector (x, y, z)
- Last digit is the camera angle (zoom), ranging form [0, 180] degrees

**'L'** is the/a lamp (you need at least one)
- First 3 digits are the x,y,z coordinates
- Next digit is the light intensity in the range [0,1]
- Last three digits are the color of the light in r,g,b [0,255]

Once you have these three, you can add more lamps, spheres, cylinders, planes as follow

```bash
L -5,2,0 0.3 0,125,255
sp -3,-11,0 3 255,120,0
pl 9,0,0 1,0,0 128,150,128
cy 6,4,-8 0,1,0 2 8 120,40,200
```
**'sp'** is a sphere:
- first three digits are x,y,z coordinates of centre of the sphere
- next digit is the radius of the sphere
- last three digits are the r,g,b colors

**'pl'** is a plane:
- first three digits are x,y,z coordinates of intersect with the plane
- next three digits form the normalized orientation vector (direction)
- last three digits are the r,g,b colors

**'cy'** is a cylinder:
- first three digits are x,y,z coordinates of centre of the cylinder
- next three digits form the normalized orientation vector (direction)
- next digit is the radius of the cylinder
- next digit is the height of the cylinder
- last three digits are the r,g,b colors


<img width="1334" alt="Screen Shot 2022-10-27 at 3 52 00 PM" src="https://user-images.githubusercontent.com/89991397/198308598-e7d7db15-8f7d-430e-bd9b-13599ec59a12.png">


## Colaboraters

This project was created by stormq4 && me.

<img width="1345" alt="Screen Shot 2022-10-27 at 3 53 43 PM" src="https://user-images.githubusercontent.com/89991397/198308551-d358c52a-ab52-4ce7-9988-7ceb5f2b009b.png">

<img width="1346" alt="Screen Shot 2022-10-27 at 3 52 17 PM" src="https://user-images.githubusercontent.com/89991397/198308274-3ea92fec-b256-4548-974f-ae32ea1c0c45.png">
