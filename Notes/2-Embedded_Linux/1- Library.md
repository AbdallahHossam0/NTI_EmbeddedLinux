# Libraries

There is 3 libraries used with Linux
- glibc: a GNU project library contains POSIX -Portable OS Interface- contains thread and pthread libraries  for Linux and standard C libraries -OS Independent- contains stdio.h, stdlib.h and stdarg.h and more
    - it is size is almost 256 MB

- uclib: not a GNU project library contains POSIX and non-POSIX and C libarrays 
    - it is a subset of glibc
    - it is size is almost 90 MB

- MUSL: not a GNU library contains POSIX and C libraries
    - it is a subset of glibc
    - it is size is almost 84 MB

uclib and MUSL mainly used for Embedded Linux. \ 
glibc: may be used in Embedded Linux in large projects with high computational performance

## Build Process

- Preprocessor:
    - remove comments and whitespace
    - checks if the file in UTF-8 format (not ascii and not UTF-32), requirements to be able to compile that file
- Compiler:
    - tokenizing
    - syntax analysis 
    - semantic analysis
    - code optimization 
    - create symbol table 
    - add debug info
    - generate assembly -target dependent-
- Linker:
    - resolve the symbol table 
    - remove unused vars and unused functions 
    - convert virtual addresses to physical addresses using the liker directory -linker file-
    - get the needed functions or vars from the .a static library


### Symbol table

| Entity | address |
| ------------------ | -----------|
| Required Entity | ***UND*** |
| Provided Entity | 0x62244f3|

it may includes global non static functions and static local vars and global non static vars and global const vars 

### RAM and ROM Sections

| RAM | 
| ---- |
| Memory mapped registers | 
| .data | 
| .bss | 
| heap (free store) | 
| stack | 


| ROM | 
| ---- |
| Vector Table | 
| .text | 
| .data initial values | 
| .ro_data | 
| boot-loader | 

## Static Libraries
- compile the code of the library using -c flag to stop the compilation process before the liker and after generation the op code from the assembler and generate the object file (.o)

- archive the files together using the ar command 

> ar rcs libName.a x.o y.o z.o 

r => for replace if found or insert if not found \
c => create the library \
s => add the symbol table 

to compile 
> gcc main.c -o funky.out -L. mylib.a


### to compile your code with the static library
```bash
gcc <my_files.c> -L. <libs path.a>
```


Note:
```bash
gcc main.c -I <path> # used to give the path of the includes 
```

### The output of the static library is the elf file

The elf file structure is

|ElF file contents|
|-|
ELF Header
Symbol Table
.vect
.text
.rodata
.data
debug symbols

The flasher don't flash all of those in the MCU Flash, it just can flash .vect, .text, .data and .rodata, it may flash the symbol table 

if the symbol table is not flashed, to debug you need to get the address of all variables

To check the type of the file
> file file-name 

### readelf -better view- and objdump -more common-
These tools are used to read the elf files
```bash
objdump -x # shows elf header, dynamic library section, code section, and symbol table

objdump -t # to show the symbol table only

objdump -s # to show the assembly code will be flashed

readelf -h # to show the elf header
```



## Dynamic -Shared- Libraries
We usually used a shared library to build the Linux from scratch

if the executable has all dependencies, then it is statically linked. but if it is dependencies will be solved by the system loader when it start executing, this means it is dynamically linked.


The main reason of dynamic linking is to save storage on RAM. One library version on RAM can be used to run multiple apps that depend on this library

Static lib is with .a extension.\
Dynamic lib is with .so {shared object} -in Linux- or .DLL {Dynamic Linked Library} -in Windows-

### System-Loader
**System-loader is responsible for solving all dynamic libraries needed by the executable that start executing**

it is a kernel component, usually used to resolve the symbol table in the run time, we can call it the **dynamic linker**

### How system-loader works?
when an app that is dynamically linked starts executing, it will get some symbols in the symbol table are not resolved yet and the file needs dynamic libraries.
1. it checks if the library is already loaded on RAM by another executable
2. if it is on RAM already, then it passes the address of the library to the program and then all symbols are resolved
3. if it is not on RAM, then 
    - it checks if there is a global variable called LD_LIBRARY_PATH and then it goes to it to search for the library \
    ```bash
        export LD_LIBRARY_PATH=~/path/to/lib
        # to delete the var 
        unset < var-name >
        unset LD_LIBRARY_PATH
    ```
    - if not found, it goes to check if the library path is given while compilation using the -wl, -rpath flag
    > gcc main.c -Wl,-rpath=path/to/library -lname -L.path/to/library -I path/to/includes -o out_file 
    - if not found, it goes to search for the library on /usr/bin and /usr/local/bin
    - if it is still not found, it throws an output, the dynamic library can't be solved
4. if the library is found in any step, system-loader loads it on RAM and solve all the dependencies and the executable start executing
5. when the program finishes successfully, system-loader checks if the library is used by another executable, if yes, it keeps it, if no, it removes it from RAM


|Static Linking|Dynamic Linking |
|-|-|
|More size in RAM and Disk needed| Less size in RAM and Disk needed|
|Fast to be loaded and start executing | Slow to be run and start executing|
|need recompilation for the application if the library is changed | no need for recompilation the application if the library changed|

Note **They are executing in the same speed as the loaded successfully**


### Check if a file is depending on dynamic library on run time or no
used **ldd command** given the name of the executable as arg
the output will be list of the dynamic libraries if exist or the output will be "not a dynamic executable"

## Let's make a dynamic library
```bash
# 1. create .c files for dynamic library

# 2. compile the .c file with flag = position independent code and get the .o files
gcc -c -fPIC fil1.c fil2.c

# 3. create a dynamic library
gcc -shared -o lib< lib-name >.so file1.o file2.o

# 4. compile the program with the dynamic library
gcc main.c -I /path/to/includes -L./lib/ -l< lib-name > -o mainDL.elf

# while compiling teh compiler checks that the given shared library can fulfill all the requirements needed by the code that's why it needs the path of the library
```

**Note**: 
- /usr/lib contains system libraries necessary for the OS and installed packages, its libs should be needed by binaries in /(s)bin or /usr/(s)bin
- /usr/local/bin contains locally installed executable files by the user. no need for these library for the os or the packages. its libs should be needed by binaries in /usr/local/bin


**Note**:
```bash
# if you have a main.c file and compiled it like that to run in linux or windows on x86 architecture
gcc (-shared) main.c # the default compile with -shared flag
# this output file is dynamically linked to prove use that 
ldd a.out # its size is 16KB
# it will show all the dynamic dependencies

# To make it statically linked you should run the compile commands as follows
gcc -static main.c # static flag will stop all dynamic linking
# the output file is statically linked to prove use that
ldd a.out # its size is 884KB, all the library are linked in the file
# it will show the that not a dynamic executable 
```

**strace**: used to trace the system calls in an executable
**ltrace**: used to trace the library calls in an executable
