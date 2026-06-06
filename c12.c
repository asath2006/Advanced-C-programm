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
struct node*middle(struct node*head)
{
    struct node*fast=head->next;
    struct node*slow=head;
    while(fast!=NULL&&fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
    
}
struct node*merge(struct node*a,struct node*b)
{
    if(a==NULL)
    {
        return b;
    }
    if(b==NULL)
    {
        return a;
    }
    struct node*result;
    if(a->data<b->data)
    {
        result=a;
       result->next=merge(a->next,b);
    }
    else
    {
        result=b;
         result->next=merge(b->next,a);
    }
    return  result;
}
struct node* mergesort(struct node*head)
{
      if(head == NULL || head->next == NULL)
        return head;
     struct node*middles= middle(head);
     struct node*nextmiddle=middles->next;
     middles->next=NULL;
    struct node*left= mergesort(head);
    struct node*right= mergesort(nextmiddle);
     return merge(left,right);
      
}
void display()
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
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
    for(int i=0;i<n;i++)
    {
        insert(a[i]);
    }
    printf("Before sorting:");
    display();
    printf("\nAfter sortin:");
   head= mergesort(head);
    display();
}
