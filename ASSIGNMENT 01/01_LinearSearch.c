#include<stdio.h>
int main()
{
    int n,key;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the numbers: ");
    for(int x= 0;x<n;x++)
    {
        scanf("%d",&arr[x]);
    }
    printf("Enter a number to be searched: ");
    scanf("%d",&key);
    for(int x= 0;x<n;x++)
    {
        if(arr[x]==key)
        {
            printf("%d is found and is present at position %d",key,x+1);
            return 0;
        }
    }
    printf("%d is not present in the given array",key);
}