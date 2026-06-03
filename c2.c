#include<stdio.h>
void swap(int*a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int partion(int a[],int low ,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}
void quicksort(int a[],int low,int high)
{
    if(low<high)
    {
        int pi=partion(a,low,high);
        quicksort(a,low,pi-1);
        quicksort(a,pi+1,high);
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
    quicksort(a,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    return 0;
}
