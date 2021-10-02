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
node *del(node *head, int pos)
{
    int i = 1;
    if (pos == i)
    {
        node *t = head;
        head = head->next;
        node *h = t->next;
        while (h->next != t)
        {
            h = h->next;
        }
        h->next = head;
        return head;
    }
    // int i=0;
    i = 2;
    node *h = head;
    h = h->next;
    while (h != head)
    {
        if ((i) == (pos))
        {
            node *t = h->next;
            h->next = t->next;
            free(t);
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
    node *h = list(10);
    display(h);
    int data = 2;
    h = del(h, data);
    display(h);
    return 0;
}