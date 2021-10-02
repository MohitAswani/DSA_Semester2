#include<stdio.h>
int main(){
    int arr[10];
    int inp=9;
    arr[(inp-1)%10]=inp;
    return 0;
}