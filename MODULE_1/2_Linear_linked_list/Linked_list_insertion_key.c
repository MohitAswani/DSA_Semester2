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
        temp->next = NULL;
    }
    return head;
}
node *ins(node *head, node *temp, int data)
{
    int i = 0;
    node *h = head;
    // if (head->data == data)
    // {

    //     return head;
    // }
    while (h != NULL)
    {
        if (h->data == data)
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
    while (h != NULL)
    {
        printf("%d ", h->data);
        h = h->next;
    }
    printf("\n");
}
int main()
{
    node *head = (node *)malloc(sizeof(node));
    node *h = list(10);
    head = h;
    display(h);
    node *insert = (node *)malloc(sizeof(node));
    insert->data = 69;
    int data = 10;
    h = ins(head, insert, data);
    display(h);

    return 0;
}