#include <stdio.h>
void swap(int *a,int *b)
{
    int t= *a;
    *a= *b;
    *b= t;
}

int partition(int arr[],int low,int high)
{
    int pivot= arr[high];
    int i= (low-1);
    for(int x= low;x<=high-1;x++)
    {
        if(arr[x]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[x]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return(i+1);
}
void quickSort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi= partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements: ");
    for (int x= 0;x<n;x++)
        scanf("%d",&arr[x]);
    quickSort(arr,0,n-1);
    printf("Sorted array: ");
    for (int x= 0;x<n;x++)
        printf("%d ",arr[x]);
}