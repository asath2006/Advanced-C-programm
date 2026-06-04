#include<stdio.h>
#define max 100
int s1[max],s2[max];
int top1=-1,top2=-1;
void push1(int v)
{
    s1[++top1]=v;
}
int  pop1()
{
   return  s1[top1--];
}
void push2(int e)
{
    s2[++top2]=e;
}
int pop2()
{
    return s2[top2--];
}
void enque(int v)
{
    if(top1==max-1)
    {
        printf("Que is full");
        return;
    }
   push1(v);
}
int isempty1()
{
    return top1==-1;
}
int isempty2()
{
    return top2==-1;
}
int deque()
{
    if(isempty1() && isempty2())
    {
        printf("Que is undrflow");
        return -1;
    }
    if(isempty2())
    {
           while(!isempty1())
           {
               push2(pop1());
           }
    }
    return pop2();
}
int main()
{
    enque(10);
    enque(20);
    enque(30);
    printf("deleted element is %d",deque());
    printf("\ndeleted elsement is %d",deque());
    
}
