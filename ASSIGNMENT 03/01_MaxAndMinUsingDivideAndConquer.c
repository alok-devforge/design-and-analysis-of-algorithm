#include<stdio.h>
#include<limits.h>
void divide(int arr[],int start,int end,int *g,int *s)
{
    if(start==end)
    {
        if (arr[start] > *g)
            *g = arr[start];
        if (arr[start] < *s)
            *s = arr[start];
        return;
    }
    if(start==end-1)
    {
        if(arr[start]>arr[end])
        {
            if (arr[start] > *g)
                *g = arr[start];
            if (arr[end] < *s)
                *s = arr[end];
        }
        else
        {
            if (arr[end] > *g)
                *g = arr[end];
            if (arr[start] < *s)
                *s = arr[start];
        }
        return;
    }
    int mid= start+(end-start)/2;
    divide(arr,start,mid,g,s);
    divide(arr,mid+1,end,g,s);
}

int main()
{
    int n, max= INT_MIN, min= INT_MAX;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the numbers in the array: ");
    for(int x= 0;x<n;x++)
        scanf("%d",&arr[x]);
    divide(arr,0,n-1,&max,&min);
    printf("Maximum number in the array is: %d \n",max);
    printf("Minimum number in the array is %d",min);
}