#include<stdio.h>
void heapify(int arr[],int n,int i)
{
    int largest=i;
    int r=2*i+2;
    int l=2*i+1;
    if(l<n&&arr[l]>arr[largest])
    largest=l;

    if(r<n&&arr[r]>arr[largest])
    largest=r;

    if(i!=largest)
    {
        int temp=arr[largest];
        arr[largest]=arr[i];
        arr[i]=temp;

        heapify(arr,n,largest);
    }
}
void build_max_heap(int arr[],int n)
{
    for(int i=n/2;i>=0;i--)
    {
        heapify(arr,n,i);
    }
}
void delete_root(int arr[],int *n)
{
    int last=arr[*n-1];
    arr[0]=last;
    *n=*n-1;
    heapify(arr,*n,0);
}
void print(int arr[],int n)
{
    printf("HEAP:");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heap_sort(int arr[],int size)
{
    build_max_heap(arr,size);
    print(arr,size);
    for (int i = size - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
        print(arr,size);
    }
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
int main(){
    
    int arr[]={1,2,3,4,5,6,9};
    int size=sizeof(arr)/sizeof(int);
    print(arr,size);
    heap_sort(arr,size);
    printf("\n");
    return 0;
}