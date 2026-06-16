#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
   char data[250];
   struct node*next;
 };
   struct node*head=NULL;
   struct node*tail=NULL;
 void insert(char songs[])
 {
    struct node*nn=(struct node*)malloc(sizeof(struct node));
    strcpy(nn->data,songs);
    nn->next=NULL;
    if(head==NULL)
    {
       head=tail=nn;
       nn->next=head;
     }
     else
     {
        tail->next=nn;
        tail=nn;
        tail->next=head;
     }
   }
void insertatposition(char songs[],int p)
{
   struct node*nn=(struct node*)malloc(sizeof(struct node));
   strcpy(nn->data,songs);
   nn->next=NULL;
   if(p==1)
   {
      head=nn;
      nn->next=head;
   }
   else
   {   struct node*temp=head;
      for(int i=1;i<p-1;i++)
      {
         temp=temp->next;
      }
      nn->next=temp->next;
      temp->next=nn;
   }
   }
 void display()
 {
    struct node*temp=head;
    do
    {
       printf("%s\n",temp->data);
       temp=temp->next;
    }while(head!=temp);
    printf("\n");
 }
int main()
{
   int n;
   printf("Enter the number of songs:");
   scanf("%d",&n);
   getchar();
   char songs[250];
   for(int i=1;i<=n;i++)
   {
       printf("Enter the %d song:",i);
      fgets(songs,sizeof(songs),stdin);
      songs[strcspn(songs,"\n")] = '\0';
      insert(songs);
    }
    printf("play list:\n");
    display();
    printf("Enter the which song will be add:");
    fgets(songs,sizeof(songs),stdin);
    printf("Which position:");
    int p;
    scanf("%d",&p);
    insertatposition(songs,p);
    display();
    
 }
    
    
