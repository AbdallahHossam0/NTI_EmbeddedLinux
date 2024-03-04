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


### Ro compile your code with the static library
```bash
gcc <my_files.c> -l <libs path.a>
```


Note:
```bash
gcc main.c -I <path> # used to give the path of the includes 
```
