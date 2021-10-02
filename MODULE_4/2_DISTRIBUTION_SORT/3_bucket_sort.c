#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct data_type
{
    double data;
    struct data_type *next;
} node;
node *insert(node *head, double data)
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
        node *head_cpy = head;
        while (head_cpy->next != NULL)
            head_cpy = head_cpy->next;

        head_cpy->next = new_node;
    }
    return head;
}
node *sorted_insertion(node *head, node *n)
{
    if (head == NULL)
    {
        head = n;
        n->next = NULL;
    }
    else
    {
        node *head_cpy = head;
        while (head_cpy->next != NULL && head_cpy->data < n->data)
            head_cpy = head_cpy->next;

        if (head_cpy->next == NULL)
        {
            if (head_cpy->data < n->data)
            {
                head_cpy->next = n;
                n->next = NULL;
            }
            else
            {
                head_cpy->next = n;
                n->next = NULL;
                double temp = head_cpy->data;
                head_cpy->data = n->data;
                n->data = temp;
            }
        }
        else
        {
            node *t=head_cpy->next;
            head_cpy->next=n;
            n->next=t;
            double temp = head_cpy->data;
            head_cpy->data = n->data;
            n->data = temp;
        }
    }
    return head;
}
node *insertionSort(node *head)
{
    node *sorted = NULL;
    node *current = head;
    while (current != NULL)
    {
        node *next = current->next;

        sorted = sorted_insertion(sorted, current);

        current = next;
    }
    return sorted;
}
void bucket_sort(double arr[],int n)
{
    node *bucket[10];
    for(int i=0;i<10;i++)
    bucket[i]=NULL;

    for(int i=0;i<n;i++)
    {
        int t=n*arr[i];
        bucket[t]=insert(bucket[t],arr[i]);
    }

    int k=0;
    for(int i=0;i<10;i++)
    {
        bucket[i]=insertionSort(bucket[i]);
        node *ptr=bucket[i];
        while(ptr!=NULL)
        {
            arr[k]=ptr->data;
            ptr=ptr->next;
            k++;
        }
    }

    for(int i=0;i<10;i++)
    {
        free(bucket[i]);
    }
}
int main(){
    double arr[]={0.12,0.34,0.01,0.94,0.34,0.1,0.2,0.5,0.2,0.0};
    int size=sizeof(arr)/sizeof(double);
    bucket_sort(arr,size);
    for(int i=0;i<size;i++)
    printf("%f ",arr[i]);
    printf("\n");
    return 0;
}