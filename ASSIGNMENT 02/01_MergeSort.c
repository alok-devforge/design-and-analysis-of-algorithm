#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int start, int mid, int end)
{
    int *temp = (int *)malloc((end - start + 1) * sizeof(int));
    int left = start, right = mid + 1, index = 0;
    while (left <= mid && right <= end)
    {
        if (arr[left] <= arr[right])
        {
            temp[index] = arr[left];
            index++, left++;
        }
        else
        {
            temp[index] = arr[right];
            index++, right++;
        }
    }
    while (left <= mid)
    {
        temp[index] = arr[left];
        index++, left++;
    }
    while (right <= end)
    {
        temp[index] = arr[right];
        index++, right++;
    }
    index = 0;
    while (start <= end)
    {
        arr[start] = temp[index];
        start++, index++;
    }
    free(temp);
}
void mergeSort(int arr[], int start, int end)
{
    if (start == end)
        return;
    int mid = start + (end - start) / 2;
    mergeSort(arr, start, mid);   // Left
    mergeSort(arr, mid + 1, end); // Right
    merge(arr, start, mid, end);
}
int main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (int x = 0; x < n; x++)
        scanf("%d", &arr[x]);
    mergeSort(arr, 0, n - 1);
    printf("Sorted Array: ");
    for (int x = 0; x < n; x++)
        printf("%d ", arr[x]);
}