

#include <stdio.h>
#define size 20

int q[20],r=-1,f=-1;

void main() 
{
  int choice=1;
  printf("1-INSERT    2-DELETE   3-DISPLAY\n");
  do
  {
   printf("Enter your choice(1/2/3): ");
   scanf("%d",&choice);
   switch(choice)
   {
     case 1: Insert();
             break;
     case 2: printf("Element at the front is deleted\n");
             Delete();
             break;
     case 3: Display();
             break;
     case 4: printf("Invalid choice\n");
            break;
   }
  }
   while(choice<=3);
}

void Insert()
{
  int item;
  printf("Enter the number to be inserted: ");
  scanf("%d",&item);
  if(r==size-1)
    printf("Queue Overflow\n");
  else
  { 
    if(f==-1)
    {
      f=0;
    }
    r=r+1;
    q[r]=item;
  }
    
}

int Delete()
{
   int item;
   if(f==-1)
     printf("Queue Empty\n");
   else
   {
     item=q[f];
     f=f+1;
     if(f==r+1)
     {
       f=r=-1;
     }
     return item;
     
   }
}

void Display()
{
   int i;
   printf("Current Elements of Queue are\n");
   for(i=f;i<=r;i++)
     printf("%d\t",q[i]);
   printf("\n");
}
