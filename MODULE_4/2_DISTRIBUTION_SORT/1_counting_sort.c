#include<stdio.h>
void count_sort(int arr[],int n,int k)
{
    int count[k];
    for(int i=0;i<k;i++)
    count[i]=0;

    for(int i=0;i<n;i++)
    count[arr[i]]++;

    for(int i=1;i<k;i++)
    count[i]+=count[i-1];

    int output[n];
    for(int i=0;i<n;i++)
    {
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }

    for(int i=0;i<n;i++)
    arr[i]=output[i];


}
void print(int arr[], int size)
{
    printf("ARRAY:");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);

    printf("\n");
}
int main(){
    int arr[]={2,6,5,3,1};
    int size=sizeof(arr)/sizeof(int);
    print(arr,size);    
    count_sort(arr,size,7);
    print(arr,size);
    return 0;
}