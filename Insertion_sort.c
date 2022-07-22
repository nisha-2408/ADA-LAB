#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void delay()
{
    int i,j,temp;
    for(i=0; i<500000; i++)
        temp=30/333;
    return;
}

void insertionSort(int arr[], int n)
{
    int i,j,key;
    for(i=1; i<n; i++)
    {
        delay();
        key = arr[i];
        j=i-1;
        while(j>=0&&key<arr[j])
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

void main()
{
    clock_t start,end;
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0; i<n; i++)
    {
        arr[i] = rand();
    }
    start=clock();
    insertionSort(arr, n);
    printf("\nArray Sorted");
    end=clock();
    printf("\nTime taken: %f",(double)(end-start)/CLOCKS_PER_SEC);
}
