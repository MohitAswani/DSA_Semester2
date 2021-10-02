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
void insertion_heapify(int arr[],int n,int i)
{
    int parent=(i-1)/2;
    if(arr[parent]>0)
    {
        if(arr[i]>arr[parent])
        {
            int temp=arr[i];
            arr[i]=arr[parent];
            arr[parent]=temp;
            insertion_heapify(arr,n,parent);
        }
    }
}
void insert(int arr[],int *n,int key)
{
    *n=*n+1;
    arr[*n-1]=key;
    insertion_heapify(arr,*n,*n-1);
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
int main(){
    int arr[10]={12,10,9,4,2,1};
    int size=6;
    build_max_heap(arr,size);
    print(arr,size);
    int k=6;
    if(arr[size-1]+arr[size-2]<k)
    {
        arr[size-1]=arr[size-1]+arr[size-2];
        size=size-1;
        insertion_heapify(arr,size,size);
    }
    print(arr,size);
    // int elem=7;
    // insert(arr,&size,elem);
    // print(arr,size);
    return 0;
}