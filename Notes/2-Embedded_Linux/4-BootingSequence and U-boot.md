# Booting Sequence
Booting Sequence is also called **Bootstrap**

## Bare-metal Booting Sequence
1. initialize the clk on the reset handler
2. initialize the SP from the first location in ROM
3. extern the linker vars and main function
4. Prepare the vector table
5. Call the reset Handler from the startup file to
    - initialize the RAM
        - copy .data initial values from ROM to RAM
        - zero the bss section
    - call the main function

writing the Stack start value in the address 0 in ROM, helps to make the micro-controller able to write the startup code in C and be able to push the context of the reset handler in the stack and start executing it.

### Boot-loader is an application
- boot-loader is an application has its own vector table and linker script and startup code 
- linker file of boot-loader constrains the length of the rom to 0x99 as example and then then the vector table is at address 0
- linker file of the main application sets the rom origin of the linker file to 0x100 as the vector table of the application should start from this address.
- so in your application you should set the vector table address to 0x100
- you can do that using the VTOR -vector table offset register- on arm and set it to 0x100 to make the PIC -peripheral interrupt controller- inside the nvic knows the vector table addresses
- each application before finish should de-init the peripheral it used, as when the called application needs to use them again it start initializing them.
- to call another application form the current application to should make the pc -program counter- start pointing to the new application reset handler

## Booting Sequence
1. Power on
2. Execute the Back BIOS from SRAM
    - Initialize the clk {HSI}
    - Initialize the DRAM
    - Convert the SRAM to be a cache memory
    - Call the BIOS
3. BIOS
    - Initialize keyboard, USB Ports and Monitor
    - Initialize the HDD and SDD
    - Boot form the given destination {SSD, HDD, or from a USB port -External Memory-}
    - Go to the partition table {MBR for Embedded Linux and Old BIOS and GPT for General Pcs} of the storage unit to load the Boot-loader from the boot-able partition and call it
4. Call Grub => Boot loader of Linux 
    - Remove the BIOS from RAM
    - initialize the Monitor 
    - load kernel Image from the DRAM -All the kernel should be loader in the RAM, The paging is done on user space level, not on the level kernel space- 
    - call the kernel
5. call the Kernel
    - Remove the boot-loader from DRAM
    - initialize keyboard, screen, and other device drivers
    - call the init-process **systemd**

In BIOS, The booting sequence is one way.
but in UEFI -Unified extensible firmware interface-, the booting sequence is two way and you can access the boot-loader and customize it from the kernel context.

your BIOS, UEFI should be able to detect the partition and able to work with the partition structure

FAT is better to be the partition structure of the kernel as it is simple, lightweight, fast, boot-able and can work with no OS

## Raspberry Pi Booting sequence

1. Boot ROM Application
    - init clk
    - call bootcode.bin
2. bootcode.bin
    - initialize DRAM
    - call start.elf
3. start.elf -runs from the DRAM-
    - call kernel
4. kernel runs

### The Booting sequence from the raspberry pi is closed source, but you can customize it using config.txt
- you can configure it to start with the u-boot instead of the kernel
- Booting sequence in RPI is executed using the GPU

on my sd card, I should have the start.elf file and config.txt file, as well as the kernel and u-boot

- **Note**: The avr linker file and startup code are closed source


## Beagle Bone Booting sequence
1. Boot Rom
    - call MLO -master boot record loader- (1st stage boot-loader)

2. MLO (2nd stage boot-loader)
    - runs using the sram
    - clk initialization
    - initialize basic hw peripherals
    - initialize dram
    - call the boot-loader (grub, lilo, u-boot)

3. boot-loader (3rd stage boot-loader)  
    - runs on the dram
    - call the kernel

4. kernel runs from the DRAM

### beagle-bone booting sequence is open source and it is written in C and you can edit on any file, but avoid changing the MLO

the sd card should contain the MLO, boot-loader and kernel

in beagle-bone, MLO searches for the boot-loader in
- **if s2 is not pressed**
    1. eMMC1
    2. MMC0
    3. uart0
    4. USB0
- **if s2 is pressed**
    1. SPI0
    2. MMC0
    3. USB0
    4. uart0

## After loading the kernel
1. sbin/init runs which is the init process -systemd-

then we have 2 options
1. shell then the terminal TTY or
2. x server -> GUI -> PTY -> shell

## QEMU
qemu is an emulator

what is the difference between emulator and simulator?
- simulator is a sw tool that used to simulate an environment and devices
- emulator is a sw or hw based tool, that is used to mimic the behavior of one system to another

## Why we need boot-loader?
1. booting the existing application (kernel) from rom to dram
2. re-flash new application

## Available boot-loaders
- grub
- u-boot (most common) 
- lilo (**li**nux **lo**ader)


## U-Boot
- has no gui (size is small)
- has its own terminal and its own commands
- mainly developed for Embedded Linux
- statically linked
- target dependent
- can interact with TFTP (Eth)

### Some Configurations
- shell prompt
- bootcmd => include commands, first thing to run after the boot is finished
- bootd => run bootcmd

### Some Commands
- setenv (var) (value)
- saveenv
- echo 
- run 
- printenv or echo $
- ls mmc 0:1
- md => memory display
- bdinfo => board information
- fatload
- bootz
- tftp

### Common variables
- kernel_addr_r => where the kernel should be loaded in RAM
- fdt_addr_r => where the dtb should be loaded


### poplar work flows
```bash
# to load the a file from sd card to RAM
fatload mmc 0:1 $kernel_addr_r /path/to/file

# To boot the kernel and the dtb from the ram 
bootz $kernel_addr_r $fdt_addr_r

# to get a file through the network Eth
tftp $kernel_addr_r  /path/to/file

# you will need to specify the board ip address and server ip addresses before get the files over the eth

setenv ipaddr 192.168.0.101
setenv serverip < Tap0 inet ip >
```

### Some notes about Linux to work with the tftp
```bash
# to test the eth status
systemctl status tftp 
```

- tftp only access the folders given in the file /etc/default/tftpd.hpa in the tftp-directory section **The default is /srv/tftp**

- but the tftp user has no access to this folder, so you need to change the the owner and group of this file to tftp or give other access to rwx




### How to work with it
- make (target machine)
- make (menuconfig)
- make 

----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------
# MBR vs GPT
they are schemes to partitioning the storage devices => ssd, hdd, sd card
they define how the partition table is laid out

|MBR|GPT|
|-|-|
master boot record | GUID partition table |
|**Advantages**| **Advantages** | size up to 9.4 zeta bytes
Compatible with older systems | up to 128 partitions which helps to multi boot
Familiarity(Used for long time) | data redundancy, copy the critical data many times across the storage devices
simple and lightweight| use of CRC32
**Disadvantages**|**Disadvantages**
up to 2 terabyte| not compatible with older systems
max is 4 primary partitions or 3 primary partitions plus 1 extended partition | more complex
data corrupted or data loss may occur


----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------
----------------------------------------------------------------

# File System
file system is a structure that used by OS to organize and manage files and their permissions

## Popular File system
FAT12, FAT16, FAT32, exFAT, NTFS, APFS, EXT3, EXT4

## FAT => File allocation table
#### FAT16, max partition size = 2GB, cluster size = 8k to 32k, max file size = 2GB
#### FAT32, max partition size = 2TB, cluster size = 4k to 32k, max file size = 4GB
#### Good solution for removable storgae devices
### Advantages 
- Simple
- easy to recover
- compatibility
- can be boot-able
### Disadvantages
- fragmentation
- no security permissions, encryption, compression
- max file name (8.3) 8 for the name and 3 for extension


## exFAT => extended file allocation table
improved version of FAT32
### Advantages 
- can handle files > 4GB
- use dynamic cluster size
- compatible with windows, linux and mac
### Disadvantages
- no security, encryption
- fragmentation


## NTFS => new technology file system
usually used for windows
### Advantages
- security and permissions for folder and files
- TRIM support for SSD, used to erase and prepare space for future writes
### Disadvantages
- reliable but errors still can occur
- NTFS repairs need time and may require tools not simple as FAT and exFAT


## ext4 => forth extended file system
usually used for linux, successor of ext3, default for many linux distributions
### Advantages
- faster recovery in case of power failures
### Disadvantages
- fragmentation
- limited scalability


## Best for small file size? 
NTFS and ext4
## Best for large file size? 
NTFS and exFAT
## for removable storage devices? 
FAT and exFAT
## Best to avoid fragmentation?
NTFS
