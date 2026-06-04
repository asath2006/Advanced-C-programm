#include<stdio.h>
#define max 100
int que[max];
int front=-1,rear=-1;
void enque(int v)
{
    if(rear==max-1)
    {
        printf("queue is full");
        return ;
    }
    if(front==-1)
    {
        front=0;
    }
    que[++rear]=v;
    printf("value %d is inserted:\n",v);
}
void deque()
{
    if(front==-1||front>rear)
    {
        printf("Invalid");
        return;
    }
    printf("Deleted elemnt is %d\n",que[front]);
    if(front==-1)
    {
        front=rear=-1;
    }
    else
    {
        front++;
    }
    
}
void display()
{ 
    if(front == -1 || front > rear)
    {
        printf("Queue is empty\n");
        return;
    }
    
    for(int i=front;i<=rear;i++)
    {
        printf("%d ",que[i]);
    }
    printf("\n");
}
int main()
{
    enque(10);
    enque(20);
    enque(30);
    display();
    deque();
    display();
    enque(40);
    enque(50);
    enque(60);
    enque(70);
    display();
}
