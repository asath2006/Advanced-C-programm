#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node*next;
};
 struct node*head=NULL;
void insert(int data)
{
  struct node*nn=(struct node*)malloc(sizeof(struct node));
  nn->data=data;
  nn->next=NULL;
  if(head==NULL)
  {
     head=nn;
  }
  else
  {
     struct node*temp=head;
     while(temp->next!=NULL)
     {
         temp=temp->next;
     }
     temp->next=nn;
 }
}
 void bubble()
 {
     int s;
    struct node*ptr=head;
    do
    {
        s=0;
       ptr=head;
      while(ptr->next!=NULL)
      {
         if(ptr->data>ptr->next->data)
         {
            int temp=ptr->data;
            ptr->data=ptr->next->data;
            ptr->next->data=temp;
            s=1;
         }
         ptr=ptr->next;
      }
  }while(s);
 }
 void display()
  {
    struct node*temp=head;
    while(temp!=NULL)
    {
       printf("%d ",temp->data);
       temp =temp->next;
    }
  }
int main()
{
   int n;
   scanf("%d",&n);
   int a[n];
   for(int i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }
   printf("Before sort:");
   for(int i=0;i<n;i++)
   {
      printf("%d ",a[i]);
   }
   for(int i=0;i<n;i++)
   {
    insert(a[i]);
  }
  printf("\n");
  bubble();
  printf("After sort:");
  display();
  return 0;
  
 }
