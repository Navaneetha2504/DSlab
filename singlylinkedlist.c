
#include<stdio.h>
#include<stdlib.h>
int count=0;
struct Node *head=NULL;
struct Node
{
	int data;
	struct Node *link;
};
void insert_at_begin(int x)
{
	struct Node *newnode;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	count++;
	if(head==NULL)
	{
		head=newnode;
		head->data=x;
		head->link=NULL;
		return;
	}
	newnode->data=x;
	newnode->link=head;
	head=newnode;
}
void insert_at_end(int x)
{
	struct Node *newnode,*ptr;
	newnode=(struct Node*)malloc(sizeof(struct Node));
	count++;
	if(head==NULL)
	{
		head=newnode;
		head->data=x;
		head->link=NULL;
		return;
	}
	ptr=head;
	while(ptr->link!=NULL)
	{
		ptr=ptr->link;
	}
	ptr->link=newnode;
	newnode->data=x;
	newnode->link=NULL;
}
void delete_from_begin()
{
	struct Node *ptr;
	int n;
	if(head==NULL)
	{
		printf("Linked List is empty!!!\n\n");
		return;
	}
	n=head->data;
	ptr=head->link;
	free(head);
	head=ptr;
	count--;
	printf("Deleted element is %d\n\n",n);
	return;
}
void delete_from_end()
{
	struct Node *ptr,*temp;
	int n;
	if(head==NULL)
	{
		printf("Linked List is empty!!!\n\n");
		return;
	}
	count--;
	if(head->link==NULL)
	{
		n=head->data;
		free(head);
		head=NULL;
		printf("Deleted element is %d\n\n",n);
		return;
	}
	ptr=head;
	while(ptr->link!=NULL)
	{
		temp=ptr;
		ptr=ptr->link;
	}
	n=ptr->data;
	temp->link=NULL;
	free(ptr);
	printf("Deleted element is %d\n\n",n);
	return;
}
void display()
{
	struct Node *ptr;
	if(head==NULL)
	{
		printf("Linked List is empty!!!\n\n");
		return;
	}
	printf("No of elements: %d\n",count);
	printf("Elements are: ");
	ptr=head;
	while(ptr->link!=NULL)
	{
		printf("%d ",ptr->data);
		ptr=ptr->link;
	}
	printf("%d ",ptr->data);
	printf("\n\n");
}
int main()
{
	int ch,data;
	while(1)
	{
		printf("---LINKED LIST PROGRAMS---\n");
		printf("1. INSERT AT BEGINING\n");
		printf("2. INSERT AT END\n");
		printf("3. DELETE FROM BEGINING\n");
		printf("4. DELETE FROM END\n");
		printf("5. DISPLAY LIST\n");
		printf("6. EXIT\n\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		if(ch==1)
		{
			printf("Enter the insert value: ");
			scanf("%d",&data);
			printf("\n");
			insert_at_begin(data);
		}
		else if(ch==2)
		{
			printf("Enter the insert value: ");
			scanf("%d",&data);
			printf("\n");
			insert_at_end(data);
		}
		else if(ch==3)
		{
			delete_from_begin();
		}
		else if(ch==4)
		{
			delete_from_end();
		}
		else if(ch==5)
		{
			display();
		}
		else if(ch==6)
		{
			break;
		}
		else
		{
			printf("Wrong choice!!!\n");
		}
	}
}
