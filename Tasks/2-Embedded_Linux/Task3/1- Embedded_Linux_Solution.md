# Embedded Linux => TASK 3 

### I generated the **arm-cortexa9_neon-linux-musleabihf** tool chain

## What is sysroot?
- sysroot folder is usually includes the dynamic libraries that the executable binary file generated by this tool is linked dynamically with.
- it also include the root that should be the root of the linux image that runs the executable file as it has the kernel headers, system libraries and configuration files.
- it is mandatory for cross compilation.



## What is Binutils?
There are some tools used for compilation and understanding the generated executables.

- ar : used to archive static libraries
- as : it the assembler, it is used to convert the assembly code into object code.
- cpp : it is the c preprocessor, used before compilation
- g++ : it is the C++ compiler, it can do all the compilation process
- gcc : it is the c compiler
- gcov : used for unit testing it offers line and branch coverage 
- gdb : it is the debugger server
- gprof : used to profile the code 
- ld : it is the linker, used to link all the objects files and libraries together
- ldd : used to get the dynamic dependencies libraries of an executable
- nm : it is used to analyze the executable and show the symbol table
- objcopy : used to generate the hex of the bin files from the elf file
- objdump : similar to nm
- readelf : similar to objdump and nm
- size : used to get the sizes of the sections in the elf file
- strings : used to extract the strings from the elf file
