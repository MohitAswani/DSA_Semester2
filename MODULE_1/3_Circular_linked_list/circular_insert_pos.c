#include <stdio.h>
#include <stdlib.h>
typedef struct data_type
{
    int data;
    struct data_type *next;
} node;
node *list(int k)
{
    node *head = (node *)malloc(sizeof(node));
    if (k == 0)
    {
        head = NULL;
    }
    else
    {
        head->data = 1;
        node *ptr = (node *)malloc(sizeof(node));
        node *temp = head;
        for (int i = 2; i <= k; i++)
        {
            node *p = (node *)malloc(sizeof(node));
            p->data = i;
            temp->next = p;
            temp = p;
        }
        temp->next = head;
    }
    return head;
}
node *ins(node *head, node *temp, int pos)
{
    int i = 0;
    node *h = head;
    node *org_head = head;
    if (pos == 1)
    {
        head = temp;
        temp->next = h;
        h = h->next;
        while (h->next != org_head)
        {
            h = h->next;
        }
        h->next = temp;
    }
    h = h->next;
    while (h != head)
    {
        if ((i + 3) == pos)
        {
            node *t = h->next;
            h->next = temp;
            temp->next = t;
        }
        h = h->next;
        i++;
    }
    return head;
}
void display(node *h)
{
    node *ptr = h;
    printf("%d ", h->data);
    h = h->next;
    while (h != ptr)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    node *h = list(3);
    head = h;
    display(h);
    node *insert = (node *)malloc(sizeof(node));
    insert->data = 111;
    int pos=2;
    h = ins(head, insert, pos);
    display(h);
    return 0;
}