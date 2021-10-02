#include<stdio.h>
void bubble_sort(int arr[],int n)
{
    int flag=0;
    for(int i=0;i<n;i++)
    {
        flag=0;
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
                flag=1;
            }
        }
        if(flag==0)
        return ;
    }
}
void print(int arr[],int n)
{
    printf("ARRAY:");
    for(int i=0;i<n;i++)
    printf("%d ",arr[i]);
}
int main(){
    int arr[]={3,4,5,2,7,2,9,3,0,45};
    int size=sizeof(arr)/sizeof(int);
    bubble_sort(arr,size);
    print(arr,size);
    return 0;
}