# Phoenix
Pheonix is EEEWA's Flagship Modulised RC Car

# Pre-Rerequisite
- CMake: https://cmake.org/download/
- ARM-Compiler: https://developer.arm.com/Tools%20and%20Software/Arm%20Compiler%20for%20Embedded

# Setup
- Quickly Automate Build and Cross Compile (Only on LINUX/MAC)
```sh
    source ./run.sh
```
- To Build and Cross Compile
```sh
    mkdir build
    cmake ..
    make
```
- Run Code On STM32
In the following folder
```sh
    build/ 
    Phoenix.bin
```
Drag and drop the Phoenix.bin into the device (STM32 should show up as USB removable flash drive)
