#include <stdio.h>
void merge(int arr[],int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    int L[n1];
    int R[n2];
    for(int i=0;i<n1;i++)
    L[i]=arr[i];
    for(int i=0;i<n2;i++)
    R[i]=arr[m+1+i];

    int i=0;
    int j=0;
    int k=1;
    while(i<n1&&j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        arr[k]=L[i];
        k++;
        i++;
    }
    while(j<n1)
    {
        arr[k]=R[j];
        k++;
        j++;
    }
}
void merge_sort(int arr[], int l,int r)
{
    if(l<r)
    {
        int m=(l+r)/2;
        merge_sort(arr,l,m);
        merge_sort(arr,m+1,r);
        merge(arr,l,m,r);
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
    merge_sort(arr, 0,size-1);
    print(arr, size);
    return 0;
}