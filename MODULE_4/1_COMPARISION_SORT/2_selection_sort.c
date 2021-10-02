#include <stdio.h>
void selection_sort(int arr[], int size)
{
    int i,j,mini;
    for(i=0;i<size-1;i++)
    {
        mini=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<arr[mini])
            mini=j;
        }
        int temp=arr[i];
        arr[i]=arr[mini];
        arr[mini]=temp;
    }
}
void print(int arr[], int size)
{
    printf("ARRAY :");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[] = {12, 11, 13, 5, 6};
    int size = sizeof(arr) / sizeof(int);
    selection_sort(arr, size);
    print(arr, size);
    return 0;
}