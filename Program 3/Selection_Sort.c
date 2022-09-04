#include <stdio.h>
#include<time.h>
#define max 5000
int a[max];
int main()
{
    int i, j, position, swap;
    clock_t start,end;
    for (i = 0; i < max; i++)
        a[i] = rand();
    start=clock();
    for(i = 0; i < max - 1; i++)
    {
        position=i;
        for(j = i + 1; j < max; j++)
        {
            if(a[position] > a[j])
                position=j;
        }
        if(position != i)
        {
            swap=a[i];
            a[i]=a[position];
            a[position]=swap;
        }
    }
    end=clock();
    printf("Array Sorted");

    printf("\nTime taken for %d values: %f",max, (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}
