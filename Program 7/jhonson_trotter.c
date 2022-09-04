#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool right = false;
bool left = true;
int posMobile(int a[], int n, int mobile)
{
    int i;
    for(i=0; i<n; i++)
    {
        if(a[i]==mobile)
            return i+1;
    }
}
int getMobile(int a[], bool dir[], int n)
{
    int temp=0, mobile, i;
    for(i=0; i<n; i++)
    {
        if(dir[a[i]-1]==right && i!=0)
        {
            if(a[i]>a[i-1] && a[i]>temp)
            {
                mobile = a[i];
                temp=mobile;
            }
        }

        if(dir[a[i]-1]==left && i!=n-1)
        {
            if(a[i]>a[i+1] && a[i]>temp)
            {
                mobile=a[i];
                temp=mobile;
            }
        }
    }
    if(mobile==0&&temp==0)
        return 0;
    else
        return mobile;
}
void Permute(int n, int arr[], bool dir[])
{
    int i, mobile, pos, temp;
    mobile = getMobile(arr, dir, n);
    pos = posMobile(arr, n, mobile);
    if(dir[arr[pos-1]-1]==right){
        temp=arr[pos-1];
        arr[pos-1]=arr[pos-2];
        arr[pos-2]=temp;
    }
    else if(dir[arr[pos-1]-1]==left){
        temp=arr[pos];
        arr[pos]=arr[pos-1];
        arr[pos-1]=temp;
    }
    for(i=0; i<n; i++)
    {
        if(arr[i]>mobile)
        {
            if(dir[arr[i]-1]==left)
                dir[arr[i]-1]=right;
            else if(dir[arr[i]-1]==right)
                dir[arr[i]-1]=left;
        }
    }
    for(i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
int fact(int n)
{
    if(n==0 || n==1)
    {
        return 1;
    }
    else
    {
        return n*fact(n-1);
    }
}
void printAll(int n)
{
    int arr[n], i;
    bool dir[n];
    for(i=0; i<n; i++)
    {
        arr[i]=i+1;
        dir[i]=right;
    }
    for(i=1; i<fact(n); i++)
    {
        Permute(n, arr, dir);
    }
}

void main()
{
    int n;
    printf("\nEnter the length of permutation: ");
    scanf("%d",&n);
    printAll(n);
}
