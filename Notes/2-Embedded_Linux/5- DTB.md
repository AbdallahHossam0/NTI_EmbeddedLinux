# DTB => Device Tree Blob

### This file is used to make the kernel independent on the internal or external interfaces 

it a description for HW connected to CPU on SOC or Board

### It's a description of the interfaces connected to the CPU and the board and their addresses, it is a dictionary => key and value

### DTB is unique for each board

**Note**: no addresses for the file register, so, the register marked variables have no addresses

DTS -------> DTC ---------> DTB \
DTS = Device Tree Source \
DTC = Device Tree Compiler \
DTB = Device Tree Blob


