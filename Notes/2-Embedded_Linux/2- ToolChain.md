# Tool Chain

The tool chain consists of: 
1. bin-utils: which includes
    - gcc
    - g++
    - ld
    - ldd
    - ar
    - objdump
    - readelf
    - cpp
    - strace 
    - strings
    - make
    - size
    - as

2. librates: glibc 
3. headers: headers for the library
4. kernel headers
5. GDB


## Types of Compilers

### Native Compilers
Compile and run on the same architecture

### Cross compiling
Compile on an architecture and run on another architecture


## cross-tool-ng
this open-source tool is used to customize the tool chain you need, you can generate the host and the target, so you can generate a native compiler or a cross compiler

### Why not use arm-none-eapi compiler directly?
this tool os based on glibc library, what is I don't want that library?

### can we use native compilers in Embedded Linux?
**yes**, but remember the low resources for the micro-processors you use, low computational power, low RAM, Lower disk size, 


### Let's work with cross-tool-ng

1. you need to clone it from the website
2. ./bootstrap
3. ./configure --enable-local
4. make
5. ./ct-ng < list-samples >
6. ./ct-ng < sample you need to start with >
7. ./ct-ng menuconfig (To enable you to customize the sample you want)
8. ./ct-ng build
9. your tool chain is ready and exists on ~/x-tools

the kconfigure directory is responsible for the gui on terminal 

### **Note**
The lib you add in the tool chain is the lib that is generated in the tool chain and you can include its headers on your project and the lib will compile it with your project


### **Remember**
I made 2 tool chains, the first with libc library and the second without any library\
The structure of the 2 directories were different, as the first one has under the include dir, there are many includes and the second doesn't have any includes. and the same under the lib dir. moreover the first one has docs about the library, and the second doesn't have any docs about libs.



## Notes
strace => used to trace the system calls of an executable\
ltrace => used to trace the library calls of an executable\


The generated tool chain is dynamically linked to libc library to make it statically linked you have an option in the gui

