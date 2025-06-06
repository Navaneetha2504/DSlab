#include <stdio.h>
void sort(int*,int);

void main()
{
  int a[20],i,n;
  printf("Enter the number of numbers for sorting: ");
  scanf("%d",&n);
  printf("Enter %d numbers\n",n);
  for(i=0;i<n;i++)
  {
    scanf("%d",a+i);
  }
  sort(a,n);
  printf("Sorted list is\n");
  for(i=0;i<n;i++)
  {
    printf("%d\n",*(a+i));
  }
}

void sort(int* a,int n)
{
  int i,j,temp;
  for(i=0;i<n-1;i++)
  {
    for(j=0;j<n-i-1;j++)
    {
      if(*(a+j) > *(a+j+1))
      {
         temp=*(a+j);
         *(a+j)=*(a+j+1);
         *(a+j+1)=temp;
      }
    }
  }
}
