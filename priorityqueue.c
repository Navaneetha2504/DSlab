
#include <stdio.h>
#define N 20

int Q[N];
int Pr[N];
int r = -1, f = -1;

void enqueue(int data, int p)
{
    if (r == N - 1)
        printf("Queue is full");
    else 
    {
        if (f == -1)
        {
            f = r = 0;
            Q[r] = data;
            Pr[r] = p;
        }
        else
        {
            r++;
            int i = r;
            while (i > 0 && p < Pr[i - 1]) 
            { 
                Q[i] = Q[i - 1];
                Pr[i] = Pr[i - 1];
                i--;
            }
            Q[i] = data;
            Pr[i] = p;
        }
    }
}

void display() 
{
    if (f == -1)
        printf("Queue is Empty");
    else
    {
        int i;
        for (i = f; i <= r; i++) 
        {
            printf("\nElement = %d\tPriority = %d", Q[i], Pr[i]);
        }
    }
}

void dequeue() 
{
    if (f == -1)
        printf("Queue is Empty");
    else 
    {
        printf("Deleted Element = %d\tIts Priority = %d", Q[f], Pr[f]);
        if (f == r)
            f = r = -1;
        else
            f++;
    }
}

void main() 
{
    int opt, n, i, data, p;
    printf("Enter Your Choice:-");
    do 
    {
        printf("\n\n1 for Insert the Data in Queue\n2 for Show the Data in Queue \n3 for Delete the data from the Queue\n0 for Exit\n");
        scanf("%d", &opt);
        switch (opt)
         {
            case 1:
                printf("\nEnter the number of data: ");
                scanf("%d", &n);
                printf("\nEnter your data and Priority of data: ");
                i = 0;
                while (i < n)
                {
                    scanf("%d %d", &data, &p);
                    enqueue(data, p);
                    i++;
                }
                break;
            case 2:
                display();
                break;
            case 3:
                dequeue();
                break;
            case 0:
                break;
            default:
                printf("\nIncorrect Choice");
        }
    } 
    while (opt != 0);
}
