#include<stdio.h>
#include<time.h>

#define max 13000

int number[max];

void delay() {
    int i, temp;
    for(i=0;i<5000;i++){
    temp = 33/333;
    }
}

void quicksort(int number[max],int first,int last)
{
    int i, j, pivot, temp;
    delay();
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
        while(i<j)
        {
            while(number[i]<=number[pivot]&&i<last)
                i++;
            while(number[j]>number[pivot])
                j--;
            if(i<j)
            {
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
            }
        }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
    }
}
int main()
{
    clock_t start, end;
    int i;
    for(i=0; i<max; i++)
        number[i] = rand();
    start=clock();
    quicksort(number,0,max-1);
    end=clock();

    printf("Elements sorted ");
    printf("\nTime taken to sort %d values: %f", max, (double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}

