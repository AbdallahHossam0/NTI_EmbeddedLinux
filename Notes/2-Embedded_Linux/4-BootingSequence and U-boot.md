# Booting Sequence
Booting Sequence is also called **Bootstrap**

## Bare-metal Booting Sequence
1. initialize the clk 
2. initialize the SP from the first location in ROM
3. extern the linker vars and main function
4. Prepare the vector table
5. Call the reset Handler from the startup file to
    - initialize the RAM
        - copy .data initial values from ROM to RAM
        - zero the bss section
    - call the main function

writing the Stack start value in the address 0 in ROM, helps to make the micro-controller able to write the startup code in C and be able to push the context of the reset handler in the stack and start executing it.

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
    - Go to the partition table of the storage unit to load the Boot-loader location and call it
4. Call Grub => Boot loader of Linux 
    - Remove the BIOS from RAM
    - initialize the Monitor 
    - load kernel Image from the DRAM
    - call the kernel
5. call the Kernel
    - Remove the boot-loader from DRAM
    - initialize keyboard, screen, and other device drivers
    - call the init-process **systemd**
