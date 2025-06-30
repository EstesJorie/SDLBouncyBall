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

### Compliation (*macOS/Linux/Windows*)
To compile via GCC:
```bash
gcc $(sdl2-config --cflags --libs) main.c -lm -o "Bouncing Circle"
```
> *-lm* links the required math library

> *$(sdl2-config --cflags --libs)* adds the required SDL2 configuration headers and libraries

To compile via Clang (*macOS/Linux*):
```bash
clang $(sdl2-config --cflags --libs) main.c -lm -o "Bouncing Circle"
```

To compile via MSVC (*Windows*):
```bat
cl /I"path\to\SDL2\include" main.c /link /LIBPATH:"path\to\SDL2\lib" SDL2.lib SDL2main.lib user32.lib gdi32.lib shell32.lib
```
#### Note

> This assumes that SDL2 is set up in Visual Studio project/environment

### Windows

This project includes a `build.bat` file that is located in the `build\` folder.

### To build the project:

1. Open a **Command Prompt** and navigate to the project root directory (i.e. `build.bat` is located):

    ```cmd
    cd path\to\your\project
    ```

2. Run the build script:

    ```cmd
    build.bat
    ```

This will compile the source code and output the executable **Bouncing Circle.exe** in the project root folder, and copy the required SDL2 DLL for you.

#### Note
To remove the build/executable: 

Simply delete the **Bouncing Circle.exe** and `SDL2.dll` manually from the project root folder, or run:

```cmd
del "Bouncing Circle.exe"
del SDL2.dll
```

To run:
```bash
./"Bouncing Circle"
```

## Files

- main.c = main source file with SDL loop and logic 

## Note(s)

The velocity of the circle **(vx, vy)** is updated every frame dependent on gravity and the dampening factor when bouncing on the edge of the frame. 

Debug output for the position and velocity is printed every ten frames in the function *updatePosition()*

