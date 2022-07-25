/*
  3934655                                          Exercise 1
  Marotya Mandile

  Using Windows Powershell
*/

#include <stdio.h>

int main(){
double a=65.52;
char b=15;
int c=5;

double *x;
x=&a;

char *y;
y=&b;

int *z;
z=&c;

printf("The address 0x%x, has value %d, and the memory size is %d bytes.\n",x,a,sizeof(a));
printf("The address 0x%x, has value %d, and the memory size is %d bytes.\n",y,b,sizeof(b));
printf("The address 0x%x, has value %d, and the memory size is %d bytes.",z,c,sizeof(c));


}