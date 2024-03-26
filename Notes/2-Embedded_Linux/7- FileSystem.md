# Root File System

- we should generate this root file system and put it into the second partition which is of ext4 structure
- the root file system is a combination of 
    1. the sys root of the tool chian
    2. the output compiled file from the busy box
    3. you should also create other empty necessary directories such a
        - home 
        - srv 
        - proc 
        - etc 
        - dev 
        - sys 
        - mnt
    - sudo mkdir home srv proc etc dev sys mnt

### Remember that 
- bin and sbin folder are usually a soft link to usr/bin and usr/sbin
- busy box has no bash 
- the default shell is ash
- busy box gives me the linux basic binaries, for more binaries, => clone, compile, combine, as you did with the cross tool chain

## To work with it
1. clone
2. make menuconfig {choose which binaries to include in filesystem}
3. pass the arch, and the cross tool chain
4. make install
5. the binaries are in _install directory


**You have to change all these dirs own and group to be root:root**
chown -R root:root rootfs/*

```bash
# you can use cp or rsync
cp < src > < dst >
rsync -a < src > < dst >

# to copy with out changing the ownership and group of file use 
cp -P
```


## What is Busy Box
- it is a tool used to generate the root file system, it has a terminal GUI to choose which commands to include.
- it has all the source code of all commands, then it take the tool chain and the arch for  the target and build all the chosen commands
- the output is in busybox/_install/

the binaries generated from the busy box are dynamically linked, you can check that using the ldd of the tool chain 

- Most of commands are open source and you can build them yourself and include them to your directory

- finally you should make bootargs like that
```bash
bootargs=console=ttyAMA0 root=/dev/mmcblk0p2 rootfstype=ext4 rw init=/sbin/init
```

## /proc + /sys
- those files are stored in RAM, and their size on the disk is 0
- these files should have their unique file system structure 
- proc has proc file system 
- sys has sysfs file system

### To apply those 
```bash
mount -t proc null /proc/
mount -t sysfs null /sys/

# -t is used to provide the type
# null is just a comment put it with any value 

# To show the mount points 
mount
```

### The init process created with the busy box, is the busy box init by default 


# Remember
```bash
# to show all the processes
ps -a 
```


