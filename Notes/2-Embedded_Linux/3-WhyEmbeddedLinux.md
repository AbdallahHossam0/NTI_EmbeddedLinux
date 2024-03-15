# Why Embedded Linux?

## Bare-metal drawbacks
- to change small line of code you need recompilation and re-flashing 
- fetch from ROM (slow)
- SRAM is usually used (high cost - low density)
- can't develop on runtime 
- static OS

So we go to embedded Linux for more powerful applications 

## Embedded Linux
- Linux as OS needs MMU (CPU peripheral) to manage paging and use DRAM
- powerful OS
- no need to re-flash and recompile the whole application, just compile the part you edited
- can develop on runtime
- changing in user space, no need to recompile the kernel
- dynamic OS, tasks can be added and removed on runtime (Round-Robin)
- There is RTLinux => real-time linux
 

## ARM Families
| Cortex M | Cortex R | Cortex A|
| --- | --- | -- |
|low cost |real time| advanced family |
|single core |multi-core| multi-core and most powerful |
| 48 to 600MHz | max 1GHz | 1.5 to 3 GHz|
|-|-| has MMU|
|IOT, wearables and electrometer | Automotive | smart phones and TVs and automotive informatics systems|


### Boards components
- ARM Cortex-A CPU (conatins MMU and S-RAM -cache-)
- emmc => Embedded Multi-Media Card
- mmc =>  Multi-Media Card
- DRAM
- GPIO
- Eth

### In Linux tasks in user space can't contact the HW directly, this should pass on the kernel (NO CDD)
APP is independent of HW (100%)

### Application Embedded Linux is used in
- IOT
- informatics systems
- smart TVs


## Why Linux?
- free
- open source 
- fast development
- safe, secure (very powerful crypto stack)
- support huge number of device drivers
- support different platforms
- support plug and play 

## Embedded Linux Positions
- Application Engineer (User Space) develops apps and libs using C++
- System Integrator (YOCTO and Build root)
- BSP -Board Support Package- write device support in the kernel space


### Why modern C++?
- secure and safe (tries to convert all run time errors to be compile time errors)
- library support and huge number of built-in functionality
- extremely fast like C

