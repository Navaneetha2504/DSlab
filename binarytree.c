
#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *lchild;
  struct node *rchild;
};

void BuildTree(struct node *ptr,int item)
{
  struct node *LC,*RC;
  int left,right;
  char opt;
  if(ptr!=NULL)
  {
    ptr->data=item;
    printf("Does node have left subtree?(Y/N) ");
    scanf(" %c",&opt);
    if(opt=='Y')
    {
      LC=(struct node*)malloc(sizeof(struct node));
      ptr->lchild=LC;
      printf("Enter the data: ");
      scanf("%d",&left);
      BuildTree(LC,left);
    }
    else
    {
      ptr->lchild=NULL;
    }
    
    printf("Does node have right subtree?(Y/N) ");
    scanf(" %c",&opt);
    if(opt=='Y')
    {
      RC=(struct node*)malloc(sizeof(struct node));
      ptr->rchild=RC;
      printf("Enter the data: ");
      scanf("%d",&right);
      BuildTree(RC,right);
    }
    else
    {
     ptr->rchild=NULL;
    }
  }
}

void Inorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    Inorder(ptr->lchild);
    printf("%d\t",ptr->data);
    Inorder(ptr->rchild);
  }
}

void Preorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    printf("%d\t",ptr->data);
    Preorder(ptr->lchild);
    Preorder(ptr->rchild);
  }
}

void Postorder(struct node *ptr)
{
  if(ptr!=NULL)
  {
    Postorder(ptr->lchild);
    Postorder(ptr->rchild);
    printf("%d\t",ptr->data);
  }
}
void main() 
{
  struct node *root=NULL;
  int choice=1,item;
  printf("1-INSERT\n2-INORDER\n3-PREORDER\n4-POSTORDER\n");
  do
  {
    printf("Enter your choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:printf("Enter the data of root: ");
            scanf("%d",&item);
            struct node *newnode=(struct node*)malloc(sizeof(struct node));
            if(root==NULL)
            {
             root=newnode;
            }
            BuildTree(root,item);
            break;
      case 2:printf("Inorder traversal\n");
            Inorder(root);
            printf("\n");
            break;
      case 3:printf("Preorder traversal\n");
             Preorder(root);
             printf("\n");
             break;
      case 4:printf("Postorder traversal\n");
             Postorder(root);
             printf("\n");
             break;
      default:printf("Invalid choice\n");
              break;
    }
  }
  while(choice<=4);
}
