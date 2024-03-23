# Init Process 

- this the first process to run on the system, all other processes will be forked (spawn) from this process
- it is id is 1
- its path is /sbin/init
- it usually runs the shell

- for busy box init process, it needs a configuration file called inittab (this file exists in the old Unix/Linux systems) [not on my ubuntu system]

```bash
::sysinit:/etc/rcs
::askfirst:/bin/sh
```

- this means after the init process finish it runs the rcS bash file then ask to run the shell
- you can put the mount for /sys and /proc in the rcS file
- rcS = run command Start
- the rcS file is on /etc/init.d

## Init Process Types
1. Busybox => simple and lightweight
2. systemV => on UNIX
3. systemd => on Linux

## 1. Busybox
- inittab
- rcS

## 2. SystemV
it has 7 modes:
1. Runlevel 0: **Halt or shutdown mode.** The system is powered off or shut down gracefully.

2. Runlevel 1: **Single-user or maintenance mode.** Only a single user can log in, and only essential system services are started.

3. Runlevel 2: **Multi-user mode with no network services.** The system is in a state where multiple users can log in, but network services are not yet available.

4. Runlevel 3: **Multi-user mode with full network support.** This is a standard operating mode for many Unix systems, where multiple users can log in, and all network services are operational.

5. Runlevel 4: **Undefined or user-definable runlevel.** In most System V implementations, Runlevel 4 is unused by default and available for user customization.

6. Runlevel 5: **Multi-user mode with full network support and a graphical user interface (GUI).** This mode is similar to Runlevel 3 but includes the graphical environment for users who prefer a GUI interface.

7. Runlevel 6: **Reboot mode.** The system initiates a reboot, shutting down all running processes and restarting the system.

---
---
---
---
---


- I also have the inittab and i have 7 rcs.d folders 
- each folder has files should run when this mode starts
- it has 2 types of files
    - files starts with s to start this service
    - files starts with k to kill this service
- the rcs file runs and check the mode i need to run in
- then loops to all the files, any file start with s, starts this service and any file starts with k, kills this service 

---
---
---
---
those files are soft link to files in the init.d folder with a changed name.\
the name format is as follows
{S/K}{01: 2 numbers representing the priority}{the main file name}

---
---
---
inittab

```
# each time any mode of 12345 runs, run the rcS
comment:12345:sysinit:etc/rcS
# each time mode 1 runs, run rcS with arg 1
comment:1:wait:etc/rcS 1
```


### SystemV
- it needs 7 mode dirs to work + initd folder
- it needs 2 file {iniitab, rcs}


## Task
- write script to run a program when entering mode 3 
- it should be killed it switches to mode 5

```bash
case $1
start) start_stop_demean --start /path/to/bin&;;
stop) start_stop_demean --stop /path/to/bin&;;
esac

#this & to make the task a back ground task
```
- to switch between mode 
telinit {mode number}

