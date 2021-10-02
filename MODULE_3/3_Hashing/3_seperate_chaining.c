#include <stdio.h>
#include <stdlib.h>
typedef struct data_type
{
    int data;
    struct data_type *next;
} node;
node *insert(int data, node *head)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = data;
    new_node->next = NULL;
    if (head == NULL)
    {
        head = new_node;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    return head;
}
int main()
{
    node *heads[10];
    for (int i = 0; i < 10; i++)
    {
        heads[i] = NULL;
    }
    int inp;
    scanf("%d", &inp);
    while (inp != -1)
    {
        heads[inp % 10] = insert(inp, heads[inp % 10]);
        scanf("%d", &inp);
    }
    free(heads);
    return 0;
}