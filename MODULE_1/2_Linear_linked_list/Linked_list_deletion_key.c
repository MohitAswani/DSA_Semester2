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
node *del(node *head,int pos)
{
    if(pos==head->data)
    {
        node *t=head;
        head=head->next;
        free(t);
        return head;
    }
    int i=0;
    node *h=head;
    while(h!=NULL)
    {
        if(pos-1==h->data)
        {
            node *t=h->next;
            h->next=t->next;
            free(t);
        }
        h=h->next;
        i++;
    }
    return head;
}
void display(node *h)
{
    while (h != NULL)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}
int main(){
    node *head=(node *)malloc(sizeof(node));
    node *h=list(10);
    head=h;
    display(h);
    int data=4;   
    h=del(head,data);
    display(h);
    return 0;
}