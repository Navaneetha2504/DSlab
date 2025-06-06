
#include <stdio.h>

char s[20];
int top=-1;
#define size 20

void push(char x)
{
  if(top==size-1)
  {
    printf("Stack overflow\n");
  }
  else
  {
    top=top+1;
    s[top]=x;
  }
}

char pop()
{
  if(top==-1)
  {
   printf("Stack underflow\n");
  }
  else
  {
    char x=s[top];
    top=top-1;
    return x;
  }
}
void main()
{
 char str[25];
 int i,pal=1;
 printf("Enter the string: ");
 scanf(" %[^\n]",str);
 for(i=0;str[i]!='\0';i++)
 {
   push(str[i]);
 }
 
 for(i=0;str[i]!='\0';i++)
 {
   if(str[i]!=pop())
   {
      pal=0;
      break;
   }
 }
 if(pal==1)
 {
   printf("Palindrome\n");
 }
 else if(pal==0)
 {
  printf("Not Palindrome\n");
 }
}
