
#include<stdio.h>
#define size 3

int cq[20],r=-1,f=-1;

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
     case 2: Delete();
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
  if(f==(r+1)%size)
    printf("Queue Overflow\n");
  else
  { 
    if(f==-1)
    {
      f=0;
    }
    r=(r+1)%size;
    cq[r]=item;
  }
    
}

int Delete()
{
   int item;
   if(f==-1)
     printf("Queue Empty\n");
   else
   {
     item=cq[f];
     f=(f+1)%size;
     if(f==(r+1)%size)
     {
       f=r=-1;
     }
     return item;
     
   }
}

void Display()
{
   int i;
   if(f==-1)
     printf("Queue is empty\n");
   else if(f<=r)
   {
   for(i=f;i<=r;i++)
     printf("%d\t",cq[i]);
   printf("\n");
   }
   else 
   {
      for(i=f;i<size;i++)
        printf("%d\t",cq[i]);
      for(i=0;i<=r;i++)
        printf("%d\t",cq[i]);
      printf("\n");
   }
}
