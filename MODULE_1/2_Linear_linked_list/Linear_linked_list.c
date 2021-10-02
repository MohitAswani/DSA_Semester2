#include<stdio.h>
#include<stdlib.h>
typedef struct data_type{
    int data;
    struct data_type *next;
}node;
node *list(int k)
{
    node *head=(node *)malloc(sizeof(node));
    if(k==0)
    {
        head=NULL;
    }
    else
    {
        head->data=1;
        node *ptr=(node *)malloc(sizeof(node));
        node *temp=head;
        for(int i=2;i<=k;i++)
        {
            node *p=(node *)malloc(sizeof(node));
            p->data=i;
            temp->next=p;
            temp=p;
        }
        temp->next=NULL;
    }
    return head;
}
int main(){
    node *h=list(10);
    while(h!=NULL)
    {
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");
    return 0;
}