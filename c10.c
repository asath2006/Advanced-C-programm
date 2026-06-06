#include<stdio.h>
#include<stdlib.h>
int main()
{
   int rows=3,cols=4;
   int*ar=malloc(rows *cols *sizeof(int));
   for(int i=0;i<rows;i++)
     {
     for(int j=0;j<cols;j++)
      {
        ar[i*cols+j]=i*cols+j;
       }
     }
     for(int i=0;i<rows;i++)
     {
       for(int j=0;j<cols;j++)
       {
       
       printf("%d",ar[i*cols+j]);
       }
       printf("\n");
     }
     return 0;
     }
