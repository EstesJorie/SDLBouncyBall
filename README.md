# SDLBouncyBall

A bouncing ball demo written in C using SDL2.
This project demonstrates basic 2D graphics rendering, simple physics simulation, and event handling using the SDL2 library.

---

## Build Instructions

**SDL2** is required, for this project to build correctly.

### macOS
SDL can be installed via [Homebrew](https://brew.sh/):

```bash 
brew install sdl2
```

### Windows

1. Download SDL2 development libraries from:
    https://www.libsdl.org/download-2.0.php
2. Extract files and configure complier to include SDL2 headers and link SDL2 libraries
3. Ensure SDL2.dll is in system PATH

To compile via GCC:
```bash
gcc $(sdl2-config --cflags --libs) main.c -lm -o "Bouncing Circle"
```
> *-lm* links the required math library

> *$(sdl2-config --cflags --libs)* adds the required SDL2 configuration headers and libraries

To run:
```bash
./"Bouncing Circle"
```

## Files

- main.c = main source file with SDL loop and logic 

## Note(s)

The velocity of the circle (vx, vy) is updated every frame dependent on gravity and the dampening factor when bouncing on the edge of the frame. 

Debug output for the position and velocity is printed every ten frames in the function *updatePosition()*

