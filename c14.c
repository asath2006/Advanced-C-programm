#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
   char str[250];
   struct node*next;
   struct node*prev;
};
  struct node*head=NULL;
  struct node*tail=NULL;

void insertcompartment(char str[])
{
  struct node*nn=(struct node*)malloc(sizeof(struct node));
  strcpy(nn->str,str);
  nn->next=NULL;
  if(head==NULL)
  {
     head=tail=nn;
     head->prev=NULL;
  }
  else
  {
    tail->next=nn;
    nn->prev=tail;
    tail=nn;
  }
  }
 void insertatposition(int p,char str[])
 {
    struct node*nn=(struct node*)malloc(sizeof(struct node));
    strcpy(nn->str,str);
    nn->next=NULL;
    if(p==1)
    {
       nn->next=head;
       head->prev=nn;
       head=nn;
       head->prev=NULL;
     }
     else
     {
     struct node*temp=head;
       for(int i=1;i<p-1;i++)
       {
          temp=temp->next;
       }
       nn->next=temp->next;
       temp->next->prev=nn;
       nn->prev=temp;
       temp->next=nn;
   }
   }
       
 
  void display()
  {
    struct node*temp=head;
    while(temp!=NULL)
    {
    
       printf("%s\n",temp->str);
       temp=temp->next;
     }
      printf("\n");
   }
   
  void reverse()
  {
     struct node*temp=tail;
     while(temp!=NULL)
     {
        printf("%s",temp->str);
        temp=temp->prev;
     }
     printf("\n");
   }  
  
 void deleteatposition(int d)
 {
   if(d==1)
   {
      struct node*temp=head;
      head=head->next;
      free(temp);
   }
   else
   {
       struct node*temp=head;
       for(int i=1;i<d;i++)
       {
          temp=temp->next;
       }
       temp->prev->next=temp->next;
       temp->next->prev=temp->prev;
     }
  }
       
int main()
{
  printf("Enter the number of Compartment");
  int n;
  scanf("%d",&n);
  char str[250];
  for(int i=0;i<n;i++)
  {
     scanf("%s",str);
     insertcompartment(str);
  }
  display();
  reverse();
  printf("Enter which place you add:");
  int p;
  scanf("%d",&p);
  printf("Enter the compartment number:");
  scanf("%s",str);
  insertatposition(p,str);
  display();
  reverse();
  printf("Enter which compartment will be delete:");
  int d;
  scanf("%d",&d);
  deleteatposition(d);
  display();
  reverse();
  return 0;
 }
