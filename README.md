Nicolas Boyer, 2024
40263939

# Project: Rainscene
This is a project created for my Computer Graphics class, written in C++ OPENGL. It requires a docker container and XLaunch to run.

Use the docker image found in the following link, and follow the instructions: https://github.com/tiperiu/COMP371_dockerimage

# How to Set Up

Here's what you have to do:

- Clone the this repository
- Clone the docker image
- Start up docker
- go in a command line, navigate to the folder for the docker image and type ./windows/interactive_run.ps1 "Path to rainscene here"
- Now that you are in the docker container, navigate to the build folder of the project (./code/build)
- Run XLaunch with default settings
- run cmake with the following command: cmake ../
- then run the following command: make
- This creates the build files for the application
- You can now run the project with the command ./rainscene

# Controls
You can move the mouse and use WASD to move the camera around the scene. 
You can press space to toggle the splashes that the raindrops make when they hit the ground.
You can press enter to toggle the rain entirely.

# Code that was not written by me:
- stb_image does not belong to me. It is a source file taken from the web in order to implement images in the project.
  It is also present in the lab capsules.
  You can find it in the lab capsules or at https://github.com/nothings/stb/blob/master/stb_image.h

- tinyobjloader is also not mine, and we were given permission to use it as well as part of our project.
   https://github.com/tinyobjloader/tinyobjloader

# Textures used (not mine)
Pavement texture
by Apoorva Joshi
https://www.manytextures.com/texture/58/outdoor-stone-tiles-pavement/

Dirt and wood textures
by Texturer.com
http://texturer.com/set1203/

Brushed Stainless Steel
by textures.com
https://www.textures.com/download/PBR1073/143069

# Models used (also not mine)
Tree, and the bark and leaves textures that come with it
by rezashams313
https://free3d.com/3d-model/tree-74556.html

Street Lamp
by taskirmaz
https://free3d.com/3d-model/street-lamp-419100.html

Low Poly Water Drop
by m53studio
https://sketchfab.com/3d-models/low-poly-water-drop-fb22818ecaa442a1aa8d6b229ece5748

Park\City Bench
by meraj16
https://free3d.com/3d-model/parkcity-bench-505537.html
