#include<stdio.h>
#include<stdlib.h>
void list(int arr[],int *brr[],int size)
{
    for(int i=0;i<size-1;i++)
    {
        arr[i]=i+1;
        brr[i]=&arr[i+1];
    }
    arr[size-1]=size;
    brr[size-1]=NULL;
}
int main(){
    int size=6;
    int arr[5],*brr[5];
    list(arr,brr,size);
    int k=0;
    while(brr[k]!=NULL)
    {
        printf("%d\n",arr[k]);
        k++;
    }
    printf("%d\n",arr[k]);

    return 0;
}