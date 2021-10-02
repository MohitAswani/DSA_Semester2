#include<stdio.h>
#include<stdlib.h>
typedef struct data_type{
    int data;
    struct data_type *next;
    struct data_type *prev;
}node;
node *list(int k)
{
    node *head=(node *)malloc(sizeof(node));
    head->prev=NULL;
    if(k==0)
    {
        head=NULL;
    }
    else
    {
        head->data=1;
        node *prev=head;
        node *temp=head;
        for(int i=2;i<=k;i++)
        {
            node *p=(node *)malloc(sizeof(node));
            p->prev=prev;
            p->data=i;
            temp->next=p;
            temp=p;
            prev=p;
        }
        temp->next=NULL;
    }
    return head;
}
void display(node *h)
{
    node *ptr = h;
    printf("%d ", h->data);
    h = h->next;
    while (h != NULL)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}
int main(){
    node *h=list(10);
    display(h);
    return 0;
}