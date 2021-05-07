# kernel-VAS-viewer
A very simple Linux kernel module to view x86 kernel VAS layout details. 

## How to run ?
- compile the linux module by cloneing repostiroy then open terminal and run make.
- ```insmod``` the module using ```sudo insmod main.ko```.
- run ```dmesg | tail -A 20```. to get last lines in kernel ring buffer.
- make sure to remove module after finishing using ```sudo rmmod main```.
