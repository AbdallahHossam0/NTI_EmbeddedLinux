# Linux Administration

## Introduction
### Open source License
- copyleft: open source projects can't be edited and converted to closed src [LGPL, GPL] => example: Linux
- permissive: open source projects can be edited and converted to closed src [MIT, BSD]

Unix and Linux are wrote in C
Linux + GNU = Distributions

Linux is hard to be hacked because:
- The huge support
- Not popular like windows

Terminal is TTY \
Terminal is the front end of the command line interface \
Bash is the back end of the command line interface "it is the command interpreter"

### Types of shells: 
- Bash shell
- SH Shell
- S Shell
- K bash shell

Console: is the window that show the info about booting, it is the first app to run, provide input and output capabilities to interact with the computer system

### Bootstrap
 * BIOS: Basic input and output system
 * grap: Boot-loader to find the kernel on the system, copy it to RAM and assign the PC to the start address of the kernel in RAM to run it
 * Kernel: initialize the the drivers then call the init process
 * Init process: the most parent process in the system, it runs the GUI
 * GUI

In linux, Everything is a file, The folder is a file

## Root File System
- / : root directory
- home: users home directories
- bin: soft link to /usr/bin
- sbin: soft link to /usr/sbin
- usr: other users applications & libraries
    - bin: commands & executable files
    - sbin: system commands & executable files
    - lib: shared library files
    - includes: contains the c libraries
- boot: kernel & boot-loader
- mnt: mount points for internal storage
- media: mount points for storage media
- etc: configuration files and startup scripts
- tmp: stores temporary files
- sys: size = 0 {it is 0 in disk as it is stored in RAM}
- dev: hardware device files (nodes)
- proc: virtual process files [the size is 0 in disk as it is stored in RAM]
- root: root home directory
- lib: soft link to /usr/lib
- opt: third parity applications
- var: files that change a lot

## Command Line
**command** [options] *args*

## Commands
- ls: to list tje files
- cd: change directory
- man: show the given command manual page
- info: to show the documentation
- type: show the type of command [alias, internal or external-in bin-] 
- cp: copy
- rm: remove
- rmdir: remove directory
- less: To show the content of a file, it is better than cat, more
- tail: to show the content of a end of file -n 10 => 10 lines from the end
- header: to show the content of a header of a file -n 15 => first 15 lines from the header
- diff: compare files line by line 
- env: To display the current Environment variables with values use
- printenv: To display the current Environment variables with values use
- alias: to list available aliases or make a new one
- unalias: to remove the given alias
- printenv PATH: to print the PATH environment variable
- set: print local, global and alias variables
- cut: work to print columns of csv files  
- wc: to count words, lines, chars, bytes and max line length of file 
- ls -i: to list i-nodes
- grep -v <text>: show anything that don't include the text passed
- uname -a: to show all the system information
- curl ifconfig.me: to get my global ip address that will help me stablish a ssh connection through different networks
 
Notes: ~ means /home/current_user \
cd - means the back directory \
you can't create directories in the root directory

## wildcards
- m*: anything starts with m
- m?s*: anything starts with m then has an unknown char then s then anything
- [a-f]: any thing starts with a a, b, c, d, e, f
- m?? anything of 3 chars starts with m

## Editors
- vim
- gedit: GUI
- nano

### Side Note:
it is always better to check add the readme file while creating a repository in github to make it create the main branch and put the readme file on it \
the master is not a branch

ctrl+c: is a signal to terminate the running process


## vim
vim is the enhanced version of veditor
it has 3 modes:
- Navigation: esc to go back from the editing
- Editing: i to go here from the navigation
- Command ':' from the navigation mode


:wq => to save then quit

yy to copy a line \
p to paste\
dd to cut a line \
/word => to search the word downwards\
?word => to search the word upwards\
to select chars => press v then go with arrow \
press v to copy and d to cut and p to paste \
to delete a char use backspace


## Environment Variables
- HOME: variable points to the home directory of the current user.
- PWD: variable stores the current working directory.
- SHELL: variable specifies the user's preferred shell.
- USER: variable holds the username of the current user.
- HOSTNAME: variable contains the name of the host (computer).
- PATH: variable lists directories where executable programs are located.

### To print a value of environment variable
- echo $variable name
### To overwrite a value of environment variable
- variable name = new data
### To append a value of environment variable
variable name = $variable name : new data

## Process
each process has an ID => PID, parent process ID => PPID 
init process is the first process to run on the system and it has ID = 0, and it is the only process that does not have a parent process \
The init process is responsible for initialization of the gnome [GIU of Linux] \
The details of processes can be found in /proc [this file is not in disk, it on RAM]

Each Process has its own memory, the process may have multiple threads to achieve concurrency to accelerate the process execution

## Variables 
- Local Variables \
Local Variables are the variables that are in the current shell only \
use set to print local, global variables  
example: my_local_variable = 5
- Global Variables \
when a parent process creates a new child process the child process inherits the global variables from the parent process \
use env or printenv to print the global variables \
example: export MY_GLOBAL_VAR = 5

note : to create a terminal from the current process {gnome-terminal}

## Bash scripting 
The bash file usually starts with #!/bin/bash \
Comments in bash starts with #

## Side Notes:
.bashrc: this file is executed every time you run the shell, it is located in the home directory, it is backup on the /etc/.bashrc or in /etc/skel/.bashrc

.profile: this file is executed every login, it is located in the home directory and it is backup on the /etc/.profile or /etc/skel/.profile

## Standard Input Output
### Redirection: it is used to redirect the output to the command from the terminal to a file
'>' overwrite the file \
'>>' append to the file \
'2>' log errors only

### Piping 
'|' This the pipe operator, it used to pipe the output of the first command as input to the second command 


## Search 
### Search for files:
> grep is the command used to search on files

```bash
grep what_you_search file_you_search_on
grep -R what_you_search folder_to_search_on_all_files_it_has
grep -i what_you_search file_you_search_on # To stop the case sensitive
grep -v sequence # To show all the lines that don't include that sequence
```

### Search location of command 
```bash
whereami command 
or
which command # Better
```

### Search the location of file or folder
- locate 
- find (-i) to remove the case sensitivity 

## Links 

### Soft Link [symbolic link][shortcut]
> ln -s src des

### Hard Link
> ln src des

## Package Manger
Each distribution has its own pkg manager \
is ubuntu it is APT => Advanced pkg tool \
APT is responsible for downloading packages and their dependencies then pass it dpkg to install them.

### Install
sudo apt install
### remove
sudo apt remove

## Archiving and Compression

### Archiving:
using tar command
> tar -cf polo.tar file1 file2 file3 ...

### Compressing: 
there is 3 compression techniques
```bash
xz polo.tar  # Output will be polo.tar.xz
bzip2 polo.tar  # Output will be polo.tar.bz2
gzip polo.tar  # Output will be polo.tar.gz
```

### De-Compressing:
```bash
unxz polo.tar.xz
bunzip2 polo.tar.bz2
gzip -d polo.tar.gz
```

### Extracting
> tar -xf polo.tar


### You can archive and compress in one go
```bash
tar -cXf polo.tar file1 file2 file3 ... 
# replace the X with
# J for xz
# j for bzip2
# z for gzip
```

### You can decompress and de-archive in one go
```bash
tar -xXf polo.tar.X
# replace the X with
# J for xz
# j for bzip2
# z for gzip
```

