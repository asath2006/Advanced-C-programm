#include <stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node*next;
};
 struct node*head;
struct node*createnode(int data)
{
    struct node*nn=(struct node*)malloc(sizeof(struct node));
    nn->data=data;
    nn->next=NULL;
    return nn;
}
void insert(int data)
{
    
        struct node*nn= createnode(data);
    
    
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
struct node*gettail(struct node*head)
{
    struct node*cur=head;
    while(cur!=NULL &&cur->next!=NULL)
    {
        cur=cur->next;
    }
    return cur;
}
struct node*partion(struct node*start,struct node*end)
{
    int pivot=end->data;
    struct node*pin=start;
    struct node*cur=start;
    while(cur!=end)
    {
        if(cur->data<pivot)
        {
            int temp=cur->data;
            cur->data=pin->data;
            pin->data=temp;
            
            pin=pin->next;
        }
        cur=cur->next;
    }
    int temp=pin->data;
    pin->data=end->data;
    end->data=temp;
    return pin;
}
void quicksort(struct node*start,struct node*end)
{
    if(start==NULL || start==end|| start==end->next)
    {
        return;
    }
    struct node*pivot=partion(start,end);
    struct node*temp=start;
    struct node*prev=NULL;
    while(temp!=pivot)
    {
        prev=temp;
        temp=temp->next;
    }
   if(prev!=NULL)
        quicksort(start,prev);
    if(pivot->next!=NULL)    
        quicksort(pivot->next,end);
    }
    

void display()
{
    struct node*temp=head;
    while(temp!=NULL)
    {
        printf("%d",temp->data);
        temp=temp->next;
    }
    printf("\n");
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
    printf("Before sorting");
    display();
    quicksort(head,gettail(head));
    printf("\nAfter sorting");
    display();

    return 0;
}
