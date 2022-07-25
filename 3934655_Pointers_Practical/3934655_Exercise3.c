/* 
   3934655                                          Exercise 3
   Marotya Mandile

   Using Windows Powershell
*/


#include <stdio.h>
int main( )
{
char c = 'Z';
char *cp = &c;
printf("cp is 0x%08x\n", cp);
printf("The character at cp is %c\n", *cp);
/* Pointer arithmetic - see what cp+1 is */
cp = cp+1;
printf("cp is 0x%08x\n", cp);
/* Do not print *cp, because it points to
memory not allocated to your program */



printf(" \n");
//(2) code that does pointer arithmetic with a pointer to an int and determine how big an int is.
int i = 6;
int *ip = &i;
printf("ip is %d.\n",ip);
printf("The integer at ip is %d\n", *ip);
/*Pointer arithmetic - ip+1*/
ip = ip+1;
printf("ip is %d\n", ip);
printf("The size of the integer is %d byte(s).\n", sizeof(*ip));
printf(" \n");



/*(3) Same idea – figure out how big a double is, by using pointer arithmetic and 
printing out the value of the pointer before andafter adding 1.*/
double d = 15.1251;
double *dp = &d;
printf("dp is %d.\n",dp);
printf("The double at dp is %f\n", *dp);
/*Pointer arithmetic - dp+1*/
dp = dp+1;
printf("dp is %d\n", dp);
printf("The size of the double is %d byte(s).\n", sizeof(*dp));
printf(" \n");

/*4. What should happen if you added 2 to the pointers from exercises 1 through 3, instead of 1?
 Use your program to verify your answer.*/
   //In exercise 1 since char's size is 1 byte, it will move 2 bytes higher.
   //In exercice 2 size of integer is 4 bytes, so if we add 2 it will move 8 bytes to the next address.
   //In exercise 3 size of double is 8 bytes , so if we add 2 to this pointer it will go 16 bytes to the next address.

return 0;
}