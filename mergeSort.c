#include <stdio.h>
#include <time.h>

#define max 2000

int a[max];
int b[max];

void delay() {
    int i, temp;
    for(i=0;i<5000;i++){
    temp = 33/333;
    }
}

void merging(int low, int mid, int high)
{
    int l1, l2, i;

    for(l1 = low, l2 = mid + 1, i = low; l1 <= mid && l2 <= high; i++)
    {
        if(a[l1] <= a[l2])
            b[i] = a[l1++];
        else
            b[i] = a[l2++];
    }

    while(l1 <= mid)
        b[i++] = a[l1++];

    while(l2 <= high)
        b[i++] = a[l2++];

    for(i = low; i <= high; i++)
        a[i] = b[i];
}

void sort(int low, int high)
{
    int mid;
    delay();
    if(low < high)
    {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid+1, high);
        merging(low, mid, high);
    }
    else
    {
        return;
    }
}

int main()
{
    clock_t start, end;
    int i;
    for(i = 0; i <= max; i++)
    {
        a[i]=rand();
    }
    start=clock();
    sort(0, max);
    end=clock();
    printf("\nList sorted\n");

    printf("\nTime taken to sort %d values: %f", max, (double)(end-start)/CLOCKS_PER_SEC);
}

