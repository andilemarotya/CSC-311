/* 
   3934655                                          Exercise 2
   Marotya Mandile

   Using Windows Powershell
*/

#include <stdio.h>
void foo1(int xval)
{
int x;
x = xval;
/* print the address and value of x here */
int *p = &x;
printf("The address 0x%x has the value %d.\n",p,x);
}
void foo2(int dummy)
{
int y;
/* print the address and value of y here */
y=dummy;
int *p0 = &y;
printf("The address 0x%x has the value %d.",p0,y);
}
int main()
{
foo1(7);
foo2(11);
return 0;
}

//The two values have the same address, that's what I notice