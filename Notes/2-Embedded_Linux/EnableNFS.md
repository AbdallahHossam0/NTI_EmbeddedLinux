sudo apt install nfs-kernel-server


 systemctl status nfs-kernel-server.service


Active: active (exited)


sudo nano /etc/exports

192.168.0.100(rw,no_root_squash,no_subtree_check)

sudo systemctl restart nfs-kernel-server.service

sudo systemctl status nfs-kernel-server.service

sudo exportfs -r

start qemu


old bootargs

setenv bootargs=console=ttyAMA0 root=/dev/mmcblk0p2 rootfstype=ext4 rw init=/sbin/init


new bootargs

setenv bootargs console=ttyAMA0 root=/dev/nfs ip=192.168.0.100:::::eth0 nfsroot=192.168.0.1:/home/abdallah/x-tools/rootfs,nfsvers=3,tcp rw init=/sbin/init

