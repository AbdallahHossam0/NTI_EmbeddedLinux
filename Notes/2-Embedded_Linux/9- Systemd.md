# Systemd

- systemd enables concurrency
- systemd interacts with units 
    - services
    - sockets
    - targets that consists of units
    - mount
    - ... more
- **manager of everything**
- not used in WSL


**unit**: any thing manged by systemd

## service file structure
myService.service
```bash

# Section 1 : Header
[unit]
Description=example systemd service unit file.
Documentation=http://dkmlkdcm.com
# this unit start after myUnit starts
After= myUnit.target
# this unit requires myUnit to be finished
Requires= myUnit.target
# this script should run before myUnit 
Before= myUnit.target
# this script should complete running as myUnit wants it
Wants= myUnit.target
# I can have multiple values of those such that
After= myUnit1.target MyUnit2.target MyUnit3.target 


# Section 2 : Development
[Unit Type] => target,  service, mount, socket
ExecStart = binary_or_script_to_run_when_the_target_starts_executing
ExecStop = binary_or_script_to_run_when_the_target_stops_executing

# You can have multiple exec starts 

Type = one of [ simple, exec, forking, oneshot, dbus, notify, notify-reload, idle]

# Section 3: install or start point
[Install]
wanted By = xxxx.target
# one xxxx.target started, my service started
```

## Properties
- systemd is a complex init process
- it can adapt the orphaned processes
- it runs over bash
- kills the zombie processes
- systemd is used in Linux systems only, while systemV is used in Unix based systems {the 2nd popular difference between Unix and Linux, the first one is open and close source}
- process management (scheduling)
- network management
- login management
- logs management
- mounting


## Systemd binaries
- systemctl [command] [service] # main commands of system ctl\
command can be
    - start: start this service immediately
    - stop : stop this service immediately
    - enable: enable auto start for this service
    - disable: disable the auto start for this service
    - list-dependencies: 
    - set-default
    - get-default
    - daemon-reload
    - cat => to read current configurations
    - show => show all available configuration
    - edit => modify the configuration {you will see the default configurations as comment}
    - it outputs
        - loaded means systemd is aware of it
        - enable, disable
        - active, inactive
- journalctl

## Systemd binaries locations
- /lib/systemd/system
- /usr/lib/systemd/system
- /etc/systemd/system {most common one} 

if you edit the configurations for systemd you need to daemon reload {newer versions of systemd do that automatically}


## Systemd Drawbacks
- single point fo failure
- complex and complicated
- large size
- not friendly with developers

## systemd Target
- it is like the systemV run levels
- the target defines the state your system should start in
    - emergency.target
    - rescue.target
    - multi-user.target(default for non graphical users)
    - graphical.target (default for graphical users)
- each target has dependencies that should run to completion 
- you can change the default target
    - > systemctl set-default < target name >
- you can print the default target
    - > systemctl get-default



# WSL
- wsl doesn't use systemd as an init process
- it uses the service command instead
```bash
service < service > start
service < service > stop
```
- WSL doesn't run many services by default

## Why not using systemd?
- service management is still required by Windows
