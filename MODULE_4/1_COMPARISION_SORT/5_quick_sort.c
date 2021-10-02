#include <stdio.h>
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int low_ind = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            low_ind++;
            swap(&arr[low_ind],&arr[j]);
        }
    }
    swap(&arr[low_ind+1],&arr[high]);
    return low_ind+1;
}
void quick_sort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void print(int arr[], int size)
{
    printf("ARRAY:");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
int main()
{
    int arr[] = {10, 90, 40, 50, 30, 45, 100,5};
    int size = sizeof(arr) / sizeof(int);
    quick_sort(arr, 0, size - 1);
    print(arr, size);
    return 0;
}