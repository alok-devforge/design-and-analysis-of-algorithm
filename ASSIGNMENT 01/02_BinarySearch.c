#include<stdio.h>
void sortArray(int arr[],int n)
{
    for(int x= 0;x<n;x++)
    {
        for(int y= x+1;y<n;y++)
        {
            if(arr[x]>arr[y])
            {
                int temp= arr[x];
                arr[x]= arr[y];
                arr[y]= temp;
            }
        }
    }
}
int main()
{
    int n,key;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    printf("Enter the numbers: ");
    int arr[n];
    for(int x= 0;x<n;x++)
    {
        scanf("%d",&arr[x]);
    }
    sortArray(arr,n);
    printf("Enter the number to be searched: ");
    scanf("%d",&key);
    int start= 0,end= n-1;
    while(start<=end)
    {
        int mid= start+(end-start)/2;
        if(arr[mid]==key)
        {
            printf("%d is found and is present at position %d",key,mid+1);
            return 0;
        }
        else if(arr[mid]<key)
            start= mid+1;
        else
            end= mid-1;
    }
    printf("%d is not present in the given array",key);
}