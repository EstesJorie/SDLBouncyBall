@echo off
REM Set your SDL2 folder inside the project
set SDL2_DIR=external\SDL2

REM Choose architecture: x64 or x86
set ARCH=x64

REM Set compiler (assuming gcc from MinGW is in your PATH)
set CC=gcc

REM Source file
set SRC=main.c

REM Output executable name
set OUT="Bouncing Circle.exe"

REM Compile command
%CC% -I"%SDL2_DIR%\include" %SRC% -o %OUT% -L"%SDL2_DIR%\lib\%ARCH%" -lmingw32 -lSDL2main -lSDL2 -lm

if %ERRORLEVEL% neq 0 (
    echo Build failed.
    pause
    exit /b %ERRORLEVEL%
)

echo Build succeeded.

REM Copy SDL2.dll to the output folder (for runtime)
copy "%SDL2_DIR%\lib\%ARCH%\SDL2.dll" .

pause
