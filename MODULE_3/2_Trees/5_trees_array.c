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
void tree_to_array(int arr[],node *root,int i)
{
    if(root==NULL)
    {
        return ;
    }
    arr[i]=root->data;
    tree_to_array(arr,root->lchild,2*i);
    tree_to_array(arr,root->rchild,2*i+1);
}
int main()
{
    node *root=NULL;
    root=insertion(10,root);
    insertion(5, root);
    insertion(4, root);
    insertion(6, root);
    insertion(3, root);
    insertion(9, root);
    insertion(19, root);
    insertion(23, root);
    insertion(16, root);
    insertion(17, root);
    insertion(12, root);
    insertion(22, root);
    insertion(26, root);
    int size=20;
    int arr[size];
    for(int i=0;i<size;i++)
    {
        arr[i]=0;
    }
    tree_to_array(arr,root,1);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    free(root);
    return 0;
}