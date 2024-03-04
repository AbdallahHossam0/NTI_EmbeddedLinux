# Linux Adminstartion 

## Commands For Embedded 
> dmesg: This command reports [log, debug] the kernel status \
we will use it to check the status of the device drivers \
this status is usually logged in the /var/log/message 

> lscpu: used to check the CPU status 

> du: disk usage usally used with -s for size -h for human readable \
Example: {du -sh} current folder, {du -sh folder or file}

> df: disk free => shows all partitions with its consumptions and free space

> strings => used to show any readable stings inside any binary[executable] 

> ps: used to report a snapshot of the current process 


## dmesg => rw- r-x r-x
to work you need to use sudo with as it access files that have these permissions rw- r-- --- and the root is the group and the owner of this files \
so only sudo can access this files, **you have 2 solutions to use this command**

- edit the permissions for all files that demsg prints and give them the permission to be able to r/w by others
- use set_user_id for dmesg to make it able to read all files it needs with the permissions of the owner \
rw- r-x r-x => chmod u+s => rws r-x r-x

### remember the whereis, which commands => they are used to find locations of commands only, it is better to use which 


ctrl + r => in vim means redo 