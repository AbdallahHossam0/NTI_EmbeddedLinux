# Network

There is 4 common protocols in Embedded Linux
- SSH    
- SCP   
- TFTP  
- NFS  

## Remember the OSI (Open System Interconnection) Layers
- Application layer
- Presentation layer
- Session layer
- Transport layer
- Network layer
- Data link layer
- Physical layer

## Remember the Reduced OSI (TCP) Layers
- Application layer
- Transport layer
- Network layer
    - ipv4 => 32 bit address (4 bytes)
    - ipv6 => 48 bit address (6 bytes) => Able to work with more connected devices
- Data link layer
- Physical layer
    - Ethernet, Wi-Fi, and DSL 
    - MAC (Media Access Control) addresses => 48 bits (6 bytes)

### Notes: 
- MAC address should be unique for each physical network card in the world. -for virtual devises a random MAC address is generated-
- IP -Internet protocol- address is unique for each device in the network

## Convert from MAC address to IP address
an Address Resolution Protocol (ARP) message is sent containing the ip address and asks who owns this ip, the owner of this ip address should sent his mac address

This table is stored in ARP cache (a table storing IP-to-MAC address mappings)

## TCP vs UDP

| TCP -Transmission Control Protocol- | UDP -User Datagram Protocol- |
|-----------------|-----------------|
| Connection oriented  | Connection less |
| data is transferred in order and with no error | there is no guarntee of the delivery of data or the order |
| larger header size as there is sequence number and acknowledge and control flags for each packet | small header size |
| hand shaking occurred | no connection setup |
| used for file transferring | used for DNS and VoIP |
| high latency | low latency |
| reliable | efficient -higher throughput- |


## Communicating Protocols used in Embedded Linux 

### SSH -Secure Shell- protocol
- Access devices over network  (Remote Access)
- Encrypted and ensures confidentiality and authentication
- **Port 22** is used.
- To use it
    - ssh username@hostname/ip
        - ssh abdallah@192.168.1.1
        - ssh abdallah@abdallah-VM

### SCP -Secure Copy-
- it runs over the SSH connection
- used for secure file transferring between client and server 
- **Port 22** is used.

### TFTP -Trivial File Transfer Protocol-
- Lightweight protocol used for transferring files between devices in a network.
- it is the light version of the FTP protocol
- It works through TCP/IP model
- **Port 69** is used.

### NFS -Network File System-
- This NFS protocol allows clients to access files and directories stored on remote servers over a network.
- **Port 2049** is used.


## Popular Network Commands 
- ifconfig -ipconfig- : it displays the interface information \
also can be used to configure network interfaces by setting parameters such as IP addresses, network masks, broadcast addresses, and MAC addresses. \
also used to activate and de-activate interfaces
```bash
ifconfig eth0 up
ifconfig eth0 down

or use ip
ip link set eth0 up/down
```
- ping IP: it is used to ping ip on the network (checks if it is connected or not)
- traceroute: show the hops till I reach my destination, usually used for debugging

ip a: shows all ips on the network I connected on 

netstat: It provides information about network connections, routing tables, interface statistics, and more
> netstat -ntupa \
n => which port \
t => TCP? \
u => UDP? \
p => program \
a = all

- ip addr add <ip_address>/<subnet_mask> dev <interface_name> \
used to add a new IP address \
The subnet represents the complete division between the network portion and the host portion of an IP address in binary form.
example: sudo ip addr add 192.168.1.10/24 dev dummy0
> ip addr add 192.168.1.10/24 dev dummy0

- tcp: used to sniff on bus 
> tcp dunp -nn -i <interface name> -w <myFile>

-nn used to make the output compliant with Wire-shark



