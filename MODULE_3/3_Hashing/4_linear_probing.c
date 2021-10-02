#include<stdio.h>
#include<stdlib.h>
int main(){
    int size=2;
    int *hash=(int *)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    {
        hash[i]=-1;
    }
    int elements=0;
    int inp;
    scanf("%d", &inp);
    while (inp != -1)
    {
        int index=(inp-1)%10;
        int fx=0;
        while(hash[index]!=-1)
        {
            index-=fx;
            fx++;
            index+=fx;
        }
        hash[index]=inp;
        elements++;
        scanf("%d", &inp);
    }
    free(hash);
    return 0;
}
