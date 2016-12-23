# Project Name
Piano using embedded linux

# Overview
This is just a project I did just to exercise and practice the concepts of embedded linux and programming, it does not have any professional purpose, but with small changes can be much more robust and more useful. Because it is a project without an operating system, it is very difficult to understand, but I did the same project using embedded linux: https://github.com/emanuel36/piano_linux_embedded

## Platform
Beaglebone

## Architecture
Debian 32 bits (Embedded Linux)

## Compilation
- make
- note: The makefile is programmed to compile on the pc (x86) and send the binary to the linux root directory.

## Usage
- Connect the components according to the mapping of the GPIOs that are in the headers (.h) files.
- Run the binary (teste.bin)

## Components
- Buttons
- LEDs
- Buzzer
