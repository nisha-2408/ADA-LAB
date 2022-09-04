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
int binary(int l,int h,int arr[],int key)
{
    int m;
    delay();
    m=(l+h)/2;
    if(l>h)
        return -1;
    if(arr[m]==key)
        return (m+1);
    else if(key>arr[m])
        return (binary(m+1,h,arr,key));
    else
        return (binary(l,m-1,arr,key));
}

int main()
{
    clock_t start,end;
    int m,l,h,flag;
    int n, arr[10000],key,i;
    printf("Enter the value of n: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
        arr[i]=i;
    key=arr[n-1];
    l=0;
    h=n-1;
    i=0;
    start=clock();
    flag=binary(l,h,arr,key);
    if(flag==-1)
        printf("\nKey not found!");
    else
        printf("\nKey found at %d position",flag);
    end=clock();
    printf("\nTime taken: %f",(double)(end-start)/CLOCKS_PER_SEC);
}

