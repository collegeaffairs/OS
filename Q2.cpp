#include<iostream>

#include<stdlib.h>
#include<stdio.h>
using namespace std;
int main() 
{
cout<<"\n The kernel version is, \n";
system("car /proc/sys/kernel/osrelease") ;
cout<<"\n The cpu space: \n";
system("cat /proc/cpuinfo | awk 'NR==3, NR==4{print}' \n ");
cout<<"\n Amount of cpu time since system was last booted is: ";
system("cat /proc/uptime \n");
system("cat /proc/meminfo | awk 'NR==1, NR==4{print $2}' \n ");
cout<<"\n Amount of free memory: \n";
system("cat /proc/merminfo  |awk 'NR = 2{Print $2}' \n ");
cout<<"\n Amount of used memory is: \n";
system("cat /proc/meninfo | awk '{ if (NR==1) a=$2; if(NR==2) b=$2 }END {print a-b} ' \n");
cout<<endl;
return(0) ;
}