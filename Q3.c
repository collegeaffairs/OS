/*
PROGRAM 1

WAP to report behaviour of Linux kernel including kernel version, CPU type and model, information on configured memory, amount of free and used memory.
*/



#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

void main()
{

	system("clear");

	system("echo");

	system("echo The CPU Model");

	system("cat /proc/Cpuinfo|grep Model|cut -c 13-15");

	system("echo The CPU Model Name");

	system("cat /proc/CPUinfo|grep -m1 'Model Name'");

	system("echo");

	system("echo The Kernel Version");

	system("cat /proc/sys/kernel/osrelease");

	system("echo");

	system("echo The amount of time CPU has spent in different modes");

	system("echo");

	system("echo User Mode \t:");

	system("cat /proc/stat|grep -m1 'CPU'|cut -c 16-19'");

	system("echo");

	system("echo The number of context switches are");

	system("cat/proc/stat|grep 'ctxt'|cut -c 6-12");

	system("echo The number of processes since system was last booted");

	system("cat/proc/stat|grep 'processes'|cut -c 11-15");

	system("echo configured memory details");

	system("echo The total memory in Kilobytes is");

	system("free -o|grep 'Mem'|cut -c 13-18");

	system("echo The used memory in Kilobytes is");

	system("free -o|grep 'Mem'|cut -c 36-40");

	system("echo The list of load average for past -1,5 and 15 minutes");

	system("cat /proc/loadavg");

}



