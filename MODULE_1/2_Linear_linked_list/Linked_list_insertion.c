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
node *ins(node *head,node *temp,int pos)
{
    int i=0;
    node *h=head;
    if(pos==1)
    {
        temp->next=head;
        return temp;
    }
    while(h!=NULL)
    {
        if((i+2)==pos)
        {
            node *t=h->next;
            h->next=temp;
            temp->next=t;
        }
        h=h->next;
        i++;
    }
    return head;
}
int main(){
    node *head=(node *)malloc(sizeof(node));
    node *h=list(10);
    head=h;
    while(h!=NULL)
    {
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");
    node *insert=(node *)malloc(sizeof(node));
    insert->data=69;
    h=ins(head,insert,11);
    while(h!=NULL)
    {
        printf("%d ",h->data);
        h=h->next;
    }
    printf("\n");

    return 0;
}