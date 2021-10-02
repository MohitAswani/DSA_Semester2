#include<stdio.h>
int get_max(int arr[],int n)
{
    int max=-__INT_MAX__;
    for(int i=0;i<n;i++)
    {
        if(max<arr[i])
        max=arr[i];
    }
    return max;
}
void counting_sort(int arr[],int n,int exp)
{
    int count[10];
    int output[n];

    for(int i=0;i<10;i++)
    count[i]=0;


    for(int i=0;i<n;i++)
    count[(arr[i]/exp)%10]++;

    for(int i=1;i<10;i++)
    count[i]+=count[i-1];

    for(int i=n-1;i>=0;i--)
    {
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }

    for(int i=0;i<n;i++)
    arr[i]=output[i];
}
void radix_sort(int arr[],int n)
{
    int max=get_max(arr,n);

    for(int exp=1;max/exp>0;exp*=10)
    {
        counting_sort(arr,n,exp);
    }
}
void print(int arr[], int size)
{
    printf("ARRAY:");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
int main(){
    int arr[]={12,34,23,65,76,342,1};
    int size=sizeof(arr)/sizeof(int);
    print(arr,size);
    radix_sort(arr,size);
    print(arr,size);
    return 0;
}