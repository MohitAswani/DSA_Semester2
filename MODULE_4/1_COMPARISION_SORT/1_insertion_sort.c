#include <stdio.h>
void insertion_sort(int arr[], int size)
{
    int i = 1, j, key;
    for (i = 1; i < size; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertion_sort(arr, size);
    print(arr, size);
    return 0;
}