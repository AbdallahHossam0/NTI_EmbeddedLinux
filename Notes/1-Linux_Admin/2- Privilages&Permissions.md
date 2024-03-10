# Permissions

## root vs sudo
### root
- root is a user which is created while installing the linux distribution
- it is ID = 0 
- it has all permissions on the system 
- its home directory path is /root

### sudo 
- sudo is a group that contains a list of users who are allowed to to get the privileges of the root user using "sudo" before the command
- to list the sudoers => sudo -l or see the content of /etc/group
- to get the privileges of the sudoers => /etc/sudoers
- To add a new user to the sudoers
    - from /etc/group add this new user to the sudo group 



## How to switch between users?
```bash
su # switch to root if no args
su root # switch to root
su abdallah # switch to abdallah

# su with option - before the user name means switch then go its home folder
```

## Passwd command
passwd command is used to change the password of the given user
if no user name is given then it will go to change the password of the current user, it is better to give the name of the user explicitly 

## /etc/passwd
this file contains all users on the machine, there are 3 types of users in the machine 
1. Normal users
2. System users 
3. Service users 

### 1. Normal users 
- this a normal user who can use the device and bash 
- Normal users IDs is from 1000:40000

### 2. System users
- These users usually run in the background
- their home directory is on /var/lib/"service-name"
- their shell is sbin/no-login or /bin/false which means they can't login on the system not have a bash
- each system user has a command
- their id is from 0:200
- chatgpt says that root user is a system user
- examples:
    - HTTP, HTTPS, TFTP, WWW, SSH

### 3. Service users
- each package has its own service user
- their ID is from 201:999
- their shell is sbin/no-login or /bin/false which means they can't login on the system not have a bash

### The Sequence is going like that:
Normal users uses the package which is a service user then the package do get its job done it uses the system users 

### /etc/passwd line format
username:x:UID:GID:Comment:home-path:bash-path \
x means password is encrypted \
UID => User ID \
GIP => Group ID

## /etc/shadow
This file's owner is the root and it is group called shadow \

-rw- r-- --- \
so to write in this file you need to be the root or to read from it you need to be a root or in the shadow group or simply use sudo 

if there is ! before the password, it means that password is locked

No of lines in /etc/shadow = no of lines in /etc/passwd

### /etc/shadow line format 
username:password:last-password-change:min-password-age:password-expiry:password-inactivity:account-expiry:reserved-for-future-use

To be able to understand them => chmod -l < username >

the password contains of \

=>$hashing-algorithm$salt$hashing-value

### /etc/group
it contains the available group \
note that: no of users < numbers of groups 

to get the access of each group, it is on /etc/sudoers

### /etc/group line format
group-name:x:GID:user1:usr2:usr3

### /etc/gshadow
it contains the groups password
No of lines in /etc/gshadow = no of lines in /etc/group


### How to add user
you can do that using the addusr command, it a bash script that is used to add the user in easy way using the built in command useradd in linux 
when the user is created a group of its name is created also. So, now my user and my primary group are ready. I can user to my primary group and this act as a secondary group for them \
I can also join other groups and these groups will be secondary groups for me, I can join the sudo group and be one of the sudoers

- each user has exact one group and unlimited number of primary groups 
- note to remember, sudo is not working with the built in commands 

### How To add group 
groupadd < group name >

this group is not a primary group for any person, similar to the sudo group.


## Quick Recap
- /etc : this dir contains info about configuration and startup configuration scripts such as .profile and .bashrc files
- /etc/passwd: contains all users (normal, system, service)
- /etc/shadow: contains hashed passwords for all users
- /etc/group: contains all available groups
- /etc/gshadow: contains passwords for all groups
- /etc/sudoers: contains the privileges for all available groups 


## Permissions
- '-' = file
- 'd' = directory
- 'c' = character device
- 'b' = block device

---|---|---
-u-|-g-|-o-

u = owner
g = group
o = other

the number after ---|---|--- represents the number of the hard links

### Simple Permissions 
- r = read
- w = write
- x = execute

default for files = 666 - umask (default = 2)\
default for directories = 777 - umask 

to change the umask just umask < new value >

for dirs to be able to execute commands to you, you have to make them executable by passing x permission

**One root / sudo you have all permissions**

### To change permissions, Use chmod
octal or word
- chmod 641
- chmod u+r
- chmod u-w
- chmod g+rwx
- chmod o-wx
- chmod +rwx (777)
- chmod +r (add r for all of them)

### to change the group of a file 
chgrp < group > < file >
chown :< group > < file >

### to change the owner of a file
chown < owner > < file >

### to change the owner and the group
chown < owner >:< group > < file >

**Note**: To change the owner of the file you need sudo or to be root, no need for that to change the group if you are the owner 

## Special Permission 

### set-user-id (works with files only)
used to make the command that interact with files while executing take the privilege as same as the owner of this file \
-rw**s**|r_x|r_x => this command has the set-user-id \
this command can be executed and take the ownership of the file if its executed by the owner, group or other as all of them has x

**S** means that set-user-id is set
**s** means that set-user-id is set and the file has x permission for the owner

> chmod 4777\
> chmod u+s

## set-group-id (works with directories only)
used to make the folders created into another folders inherit the group of the parent directory

rwx|rw**s**|r_x => this means any directory inside this folder will inherit the group of this folder 

set-group-id is inhered by the dirs

> chmod 2777\
> chmod g+s

## sticky-bit
**T** sticky bit only
**t** sticky bit and execute

rwx|rwx|rw**t**

it means only the owner of that file can delete or rename it, it is not inheritable \
you can delete the date inside that folder

> chmod 1777\
> chmod o+t

## Notes
To append user to group 
1. go and add the user explicitly to the group from /etc/group file 
2. sudo usermod -aG < group > < user > # -aG append Group

To check if a user is sudo or not:
1. check it explicitly from /etc/group 
2. sudo -l 

To remove a group
> sudo groupdel < group >
 
