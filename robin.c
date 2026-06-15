#include<stdio.h>
#include<stdlib.h>
struct node
{
  int pid;
  int bt; 
  struct node*next;
 };
 struct node*head=NULL;
 struct node*tail=NULL;
 
void insert(int i,int bt)
{
   struct node*nn=(struct node*)malloc(sizeof(struct node));
   nn->pid=i;
   nn->bt=bt;
   if(head==NULL)
   {
      head=tail=nn;
      nn->next=head;
   }
   else
   {
     nn->next=head;
      tail->next=nn;
      tail=nn;
      
   }
   }
  void  display()
   {
     struct node*temp=head;
     do
     {
       printf("%d %d\n",temp->pid,temp->bt);
       temp=temp->next;
     }while(temp!=head);
     
   }
 void roun(int tq)
 {
   int completed=0,n=0;
   struct node*pin=head;
   do
   {
   n++;
     pin=pin->next;
     
   }while(pin!=head);
   
    struct node*temp=head;
    while(completed<n)
    {
     if(temp->bt>0)
     {
        if(temp->bt>tq)
        {
           printf("p%d is executed in %d units:\n",temp->pid,tq);
           temp->bt=temp->bt-tq;
         }
         else
         {
            printf("p%d is finished in %d units:\n",temp->pid,temp->bt);
            temp->bt=0;
            completed++;
            
         }
         
      }
      temp=temp->next;
      }
      }
     
     
int main()
{
   int n;
   printf("Enter the number of process:");
   scanf("%d",&n);
   int bt;
   for(int i=1;i<=n;i++)
   {
      printf("Enter the %d Burst time:",i);
      scanf("%d",&bt);
      insert(i,bt);
   }
   printf("Enter the Quantum Time:");
   int tq;
   scanf("%d",&tq);
   roun(tq);
   return 0;
   }
