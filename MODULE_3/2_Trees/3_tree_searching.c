#include <stdio.h>
#include <stdlib.h>
typedef struct data_type
{
    int data;
    struct data_type *lchild;
    struct data_type *rchild;
} node;
node* insertion(int key, node *root)
{
    node *new_node = (node *)malloc(sizeof(node));
    new_node->data = key;
    new_node->lchild = NULL;
    new_node->rchild = NULL;
    if (root == NULL)
    {
        root = new_node;
    }
    else
    {
        node *temp = root;
        node *prev = NULL;
        while (1)
        {
            prev = temp;
            if (temp->data >= key)
            {
                temp = temp->lchild;
                if (temp == NULL)
                {
                    prev->lchild=new_node;
                    break;
                }
            }
            else
            {
                temp = temp->rchild;
                if (temp == NULL)
                {
                    prev->rchild=new_node;
                    break;
                }
            }
        }
    }
    return root;
}
void searching(int key,node *root)
{
    node *temp=root;
    while(temp!=NULL)
    {
        if(temp->data==key)
        {
            printf("ELEMENT FOUND");
            return ;
        }
        else if(temp->data>=key)
        {
            temp=temp->lchild;
        }
        else if(temp->data<key)
        {
            temp=temp->rchild;
        }
    }
    printf("ELEMENT NOT FOUND");
}
int main()
{
    node *root=NULL;
    root=insertion(5,root);
    insertion(9,root);
    insertion(4,root);
    insertion(6,root);
    searching(4,root);
    free(root);
    return 0;
}