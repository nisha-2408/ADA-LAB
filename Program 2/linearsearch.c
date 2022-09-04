#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay()
{
    int i,j,temp;
    for(i=0;i<500000;i++)
        temp=30/333;
    return;
}

int linear(int arr[],int i,int key,int n)
{
    delay();
    if(i==n)
        return -1;
    else if(arr[i]==key)
        return (i+1);
    else
        return (linear(arr,(i+1),key,n));
}

int main()
{
    clock_t start,end;
    int flag;
    int n, arr[10000],key,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        arr[i]=i;
    key=arr[n-1];
    i=0;
    start=clock();
    flag=linear(arr,i,key,n);
    if(flag==-1)
        printf("\nKey not found!");
    else
        printf("\nKey found at %d position",flag);
    end=clock();
    printf("\nTime taken: %f",(double)(end-start)/CLOCKS_PER_SEC);
}

