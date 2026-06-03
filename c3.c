#include<stdio.h>
#include<string.h>
#define max 100
char stack[max];
int top=-1;
void push(char ch)
{
    if(top<max-1)
    {
        stack[++top]=ch;
    }
}
char pop()
{
    return stack[top--];
}
int ismatch(char open,char close)
{
    if(open=='{'&&close=='}'||open=='('&&close==')'||open=='['&&close==']')
    {
        return 1;
    }
    return 0;

}
int main()
{
    char st[250];
    
    printf("Enter the pranthess");
    scanf("%s",st);
    for(int i=0;i<strlen(st);i++)
    {
        if(st[i]=='{'||st[i]=='['||st[i]=='(')
        {
            push(st[i]);
        }
        else
        {
            if(top==-1)
            {
                printf("Not balanced");
                return 0;
            }
            char open=pop();
        
        if(!ismatch(open,st[i]))
        {
            printf("Not valid");
            return 0;
        }
        }
    }
    if(top==-1)
    {
        printf("valid");
    }
    else
    {
        printf("not valid");
    }
}
