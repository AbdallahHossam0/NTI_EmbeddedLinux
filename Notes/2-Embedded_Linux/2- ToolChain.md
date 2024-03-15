# Tool Chain

The tool chain consists of: 
1. bin-utils: 
There are some tools used for compilation and understanding the generated executables.

- ar : used to archive static libraries
- as : it the assembler, it is used to convert the assembly code into object code.
- cpp : it is the c preprocessor, used before compilation
- g++ : it is the C++ compiler, it can do all the compilation process
- gcc : it is the c compiler
- gcov : used for unit testing it offers line and branch coverage 
- gdb : it is the debugger server
- gprof : used to profile the code 
- ld : it is the linker, used to link all the objects files and libraries together **-T means you will pass the linker file as input and the linker will not use the default linker file**
- ldd : used to get the dynamic dependencies libraries of an executable
- nm : it is used to analyze the executable and show the symbol table
- objcopy : used to generate the hex and the bin files from the elf file
- objdump : similar to nm
- readelf : similar to objdump and nm
- size : used to get the sizes of the sections in the elf file
- strings : used to extract the strings from the elf file

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
- strace => used to trace the system calls of an executable
- ltrace => used to trace the library calls of an executable
- kconfig dir=> this directory is responsible for showing a GUI inside the terminal and the output of this gui is stored into a config file


The generated tool chain is dynamically linked to libc library to make it statically linked you have an option in the gui

## Tool Chain Library
This library is used in the projects I compile using this tool chain, I include it in my project and the compiler will solve include the lib while linking

### Notes for me
I made 2 tool machines using cross-tool-ng, one with a libc and the other one without any libraries
- the one with the library, in the include directory, it has much more includes than the one with the library
- also, in the lib directory, the one with the library has much more libs than the one without the library
- moreover, the one with the library has doc for the library, and the other one has no docs about the library 
- size of int in avr is 2 bytes
- all libraries in the avr tool chain are statically linked as there is no Linux OS able to be the OS in an avr micro-controller
- the default linking mechanism for bare-metal programming is static, while the default linking mechanism for Linux-based programming is dynamic and the system loader will solve all the dependencies on the runtime


## Linker File also called **Linker Directory**
it is a file used by the linker to be able to link between objects files and static libraries, it helps the linker also to identify the physical addresses

the liker files mainly provide the startup code with 6 vars
1. _s_data
2. _e_data
3. _s_data_FLASH
4. _stack_start
5. _s_bss
6. _e_bss

### Linker file example for STM32F103
```ld
_stack_start = ORIGIN(RAM) + LENGTH(RAM)

MEMORY{
    FLASH(rx) : ORIGIN = 0x08000000, LENGTH = 64K
    /* 
    rx means that:
    r = means this area is a read area, code and data in this area could be read
    x = means this area is executable, code stored in this area could be executed
    so, any thing in the ROM can't be written except when re-flashing or using the flash driver
    */
    RAM(rw) : ORIGIN = 0x20000000, LENGTH = 20K
    /*
    no code in RAM so we don't need the x 
    w = means this area is writable, data can be written here
    */
}

SECTIONS{
    .isr_vector :
    {
        . = ALIGN(4);
        *(.isr_vector)
        *(.isr_vector*)
        . = ALIGN(4);
    } > FLASH
    
    .text :
    {
        . = ALIGN(4);
        *(.text)
        *(.text*)
        . = ALIGN(4);
    } > FLASH

    .rodata :
    {
        . = ALIGN(4);
        *(.rodata)
        *(.rodata*)
        . = ALIGN(4);
    } > FLASH

    // to get the load address of the .data section in flash
    _s_data_FLASH = LOADADDR(.data);

    .data :
    {
        . = ALIGN(4);
        _s_data = .;
        *(.data)
        *(.data*)
        . = ALIGN(4);
        _e_data = .;
    } > RAM AT> FLASH
    // means this section is loaded in RAM and they are "AT" FLASH
    /*
    Why we do that?
    - the .data section in ROM is loaded with the initial value of the variable.
    - once the data loaded in RAM -it is able to be changed any time- and this the current value of the variable that the program should use.
    */

    .bss :
    {
        . = ALIGN(4);
        _s_bss = .;
        *(.bss)
        *(.bss*)
        . = ALIGN(4);
        _e_bss = .;
    } > RAM

}
```
### notes:
- local const vars are guarded by the compiler, they are stored in RAM -Stack-
- global const vars are guarded by the readonly access of the ROM, they are stored in ROM

## Startup file
Startup files can be wrote using C or Assembly 
# What Startup files do?
1. extern the linker variables and the main function
2. prepare the vector table and pass it the .isr_vector FLASH Section
3. _stack_start address is passed in the the first location in the vector table -this makes us able to write the startup code in C in ARM-
4. implement the reset handler which do
    - copy .data section form the ROM to RAM
    - zero the bss section (I think it may be optional, the RAM is usually start with 0 as it is a volatile memory)
    - call main
> Example of the startup file is in the same directory

**in startup file written in C, we can see that many gcc compiler extension, -attributes- to the compiler**

### Where the Linker vars is stored?
I think they are not variables, they just point to a location.
if they are variables, they can be stored in the rodata section as they are constant or they may stored in the the section that points to its start or its end

## Tool-chain Folder structure
1. bin => includes all the bin-utils
2. include 
3. lib
4. arm-cortexa9_neon-linux-musleabihf => which includes
    1. bin
    2. include 
    3. lib
    4. **sysroot**
        1. lib => static and shared libraries for ARM
        2. usr => similar to the root folder of linux
            1. bin
            2. include
            3. lib => some for C and the other for POSIX
            4. share => docs only

this **sysroot** folder should be loaded in the target that the applications builded using this toolchain will be executed on

the tool chain also has the kernel headers of the kernel version selected while generating the toolchain
path of the kernel headers -can't be included in the user space-:
/home/abdallah/x-tools/arm-cortexa9_neon-linux-musleabihf/arm-cortexa9_neon-linux-musleabihf/sysroot/usr/include/linux

different versions of kernels may differ in drivers, as in each version modules and new function and new kernel headers are added 

the application interacts with the kernel using sys calls

while interacting with the kernel (creating device drivers), we can only include the kernel headers we can't include any libraries headers like stdio.h for example

how to print using the kernel headers, <linux/module.h> has printk function that I could use to print

all kernel headers are on <linux/xxx>

all drives in embedded linux are in the kernel space -GPIO, i2c, and spi-
you can interact with the kernel modules using files in the app space **Remember the caps lock led example**


