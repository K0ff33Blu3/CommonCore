#!/bin/bash
#	ARCH
arch=$(uname -a)

#	pCPU
pcpu=$(grep "physical id" /proc/cpuinfo | sort -u | wc -l)

#	vCPU
vcpu=$(grep processor /proc/cpuinfo | sort -u | wc -l)

#	Mem usage
mem_use=$(free --mega | awk '$1 == "Mem:" {print $3}')
mem_tot=$(free --mega | awk '$1 == "Mem:" {print $2}')
mem_per=$(free --mega | awk '$1 == "Mem:" {printf("%.2f%%", $3/$2*100)}')

#	Disk usage
disk_use=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} END {print disk_u}')
disk_tot=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_t += $2} END {printf("%.1fGb", disk_t/1024)}')
disk_per=$(df -m | grep "/dev/" | grep -v "/boot" | awk '{disk_u += $3} {disk_t += $2} END {printf("%.2f%%", disk_u/disk_t*100)}')

#	CPU load
cpu_per=$(vmstat | tail -1 | awk '{cpul=$15} {printf("%.1f%%", 100-cpul)}')

#	last boot
lb=$(who -b | awk '$1 == "system" {print $3 " " $4}')

#	LVM usage
lvm=$(lsblk | grep -q lvm && echo "yes" || echo "no")

#	TCP
tcp=$(ss -ta | grep ESTAB | wc -l)

#	User number
usr=$(users | wc -w)

#	Network
ip=$(hostname -I)
mac=$(ip link | grep "link/ether" | awk '{print $2}')

#	Sudo cmd
sudo=$(journalctl _COMM=sudo | grep COMMAND | wc -l)

#comando di stampa
echo	"	#Architecture: $arch
	#CPU physical : $pcpu
	#vCPU : $vcpu
	#Memory Usage: $mem_use/${mem_tot}MB (${mem_per})
	#Disk Usage: $disk_use/${disk_tot} (${disk_per})
	#CPU load: $cpu_per
	#Last boot: $lb
	#LVM use: $lvm
	#Connections TCP : $tcp ESTABLISHED
	#User log: 1
	#Network: IP $ip (${mac})
	#Sudo : $sudo cmd "