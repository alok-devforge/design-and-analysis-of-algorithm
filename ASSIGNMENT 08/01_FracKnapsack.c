#include <stdio.h>
#include <stdlib.h>
typedef struct
{
    int weight;
    int value;
    double ratio;
}Item;
int cmp(const void *a,const void *b)
{
    const Item *itemA= (const Item *)a;
    const Item *itemB= (const Item *)b;
    if(itemB->ratio>itemA->ratio)
        return 1;
    else if(itemB->ratio<itemA->ratio)
        return -1;
    else
        return 0;
}
double fractionalKnapsack(int capacity,Item items[],int n)
{
    double totalValue= 0.0;
    qsort(items, n, sizeof(Item),cmp);
    for(int i= 0;i<n&&capacity>0;i++)
    {
        if(items[i].weight <= capacity)
        {
            totalValue += items[i].value;
            capacity -= items[i].weight;
        }
        else
        {
            totalValue += items[i].ratio * capacity;
            capacity = 0;
        }
    }
    return totalValue;
}
int main()
{
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);
    Item items[n];
    for(int i= 0;i<n;i++)
    {
        printf("Enter weight and value for item %d: ",i+1);
        scanf("%d %d",&items[i].weight,&items[i].value);
        items[i].ratio= (double)items[i].value/items[i].weight;
    }
    int capacity;
    printf("Enter capacity of knapsack: ");
    scanf("%d",&capacity);
    double maxValue= fractionalKnapsack(capacity, items, n);
    printf("Maximum value achievable: %.2f\n", maxValue);
}