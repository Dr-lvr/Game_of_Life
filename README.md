## Conway's Game of Life (Low-Level Console Engine)

A simulation of Conway's Game of Life implemented in an unconventional ingenius way.


## Original Challenge

Creating a visual game-like simulation inside a non-graphical terminal environment, without using dedicated graphics libraries.


## Solution

The project leveraged the Windows GDI (Graphics Device Interface) to directly manipulate the console window’s pixel buffer:

SetPixel(mydc, j, i, COLOR);


This bypassed normal text-based console output and treated the console as a low-resolution graphical canvas, enabling per-frame pixel drawing.


## Core Logic

The simulation correctly implemented double-buffering, using two grids:

grid – The current generation

printGrid – The next generation buffer

This ensures all cell updates follow Conway’s rules without interfering with the current state mid-calculation.


## Revival Goals

This revival project is an opportunity to modernize architecture, improve design patterns, and enhance maintainability.


## Modernizing the Game of Life

Portability: Decouple rendering logic from simulation logic, removing Windows-specific dependencies.

UI/UX Improvements: Rebuild the rendering layer using a modern, cross-platform approach:

C++ with SFML or SDL

OR a web-based port using HTML Canvas or WebGL


## Dependency & Testing

Dependency & Module Cleanup: Refactor the original project structure (headers/, platform/, etc.) into a cleaner, more modular architecture using modern C++ features.

Testing: Add unit tests for Cell evolution rules (cellControl)


## Original Project Structure

This directory structure reflects the original, modular organization of the C++ project.


- headers/
  - Cell.h
  - CellControl.h
  - GridFunc.h
  - ... (Auxiliary logic headers)

- platform/
  - Grid.h
  - Platform.h (Windows API dependencies)

- parser/
  - Parser.cpp (Interpreter core)

- GoL_template/
  - Gosper_cannon_binary.txt (Sample data)
    

## Building and Running

Prerequisites

A C++ compiler supporting C++17 or newer

(For original Game of Life) A Windows environment with:

windows.h

GDI libraries (gdi32, user32)

## Compilation Examples

Original Game of Life (Windows):

g++ -o gol GoL_Main.cpp GridInterface.cpp -luser32 -lgdi32
