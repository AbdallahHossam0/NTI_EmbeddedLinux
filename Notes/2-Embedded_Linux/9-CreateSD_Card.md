# Create SD card

```bash
touch sd_card
#its size is 0
# how to make its size is 1GB?
# there is a file /dev/zero is an infinite file that includes nulls
# you can use it to copy about 1GB of nulls in your file to make it 1GB
# you can do that using dd command which stands for disk dump or disk duplicator
dd if=/dev/zero of=sd_card bs=1M count=1024
#or
fallocate -l 1G sd_card

# This file now called  a raw file => it includes just nulls

# if you need to make the file includes many partitions you should specify that, you need to assign a partitioning storage devices algorithm, They define the partition table, the start and the end of each partition {Common partition table algorithm in Embedded Linux is MBR -Master Boot Record-}, let's do that

cfdisk sd_card
#or
fdisk sd_card
# cfdisk has GUI and much more easy to use

# for Booting Embedded Linux, I should have 2 partitions
# 1- for kernel => FAT, Bootable, Primary
# 2- for the linux filesystem => ext4, not Bootable, extended 
# do that in the cfdisk command 

# /dev/loop is a virtual block device in Linux that allows you to mount regular files as block devices. and used to create a virtual file system without needing a physical storage

losetup -f -show --partscan sd_card
# this commands convert the file to be a storage device using the loop
# -f find empty loop
# --show show me which loop is used
# --partscan or -P to scan the partition table

# then you need to add the file system structure to each partition to organize and manage the partition files

# for the kernel you need to FAT16 is enough and for the file system, we need a more sophisticated one that support permissions and privileges like ext4

mkfs.vfat -F 16 -n boot /dev/loopXPY
mkfs.ext4 -L rootfs /dev/loopXPY

# you should replace X with the loop showed after the losetup command, and Y with the partition number which you need to use the FAT file system 

# then create a new folders to mount the storage devices, then mount them to it
mount path/to/the/loop path/to/the/folder/to/mount/in
# do it with all the partitions


# to list the available blocks
lsblk
#or
mount

# To unmount the partition 
umount /path/to/the/folder/the/partition/mounted/in

# to free the loop 
losetup -d /path/to/the/loopX
# you have to free the whole loop not a selected partition of it
```