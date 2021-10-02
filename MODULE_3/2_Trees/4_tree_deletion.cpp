#include <stdio.h>
#include <stdlib.h>
typedef struct data_type
{
    int data;
    struct data_type *lchild;
    struct data_type *rchild;
} node;
node *insertion(int key, node *root)
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
                    prev->lchild = new_node;
                    break;
                }
            }
            else
            {
                temp = temp->rchild;
                if (temp == NULL)
                {
                    prev->rchild = new_node;
                    break;
                }
            }
        }
    }
    return root;
}
node *minvaluenode(node *root)
{
    node *curr = root;
    while (curr != NULL && curr->lchild != NULL)
    {
        curr = curr->lchild;
    }
    return curr;
}
node *deletion(int key, node *root)
{
    if (key < root->data)
    {
        root->lchild = deletion(key, root->lchild);
    }
    else if (key > root->data)
    {
        root->rchild = deletion(key, root->rchild);
    }
    else
    {
        if (root->lchild == NULL && root->rchild == NULL)
        {
            return NULL;
        }
        else if (root->lchild == NULL)
        {
            return root->rchild;
        }
        else if (root->rchild == NULL)
        {
            return root->lchild;
        }
        else
        {
            node *temp = minvaluenode(root->rchild);
            root->data = temp->data;

            root->rchild = deletion(temp->data, root->rchild);
        }
    }
    return root;
}
int main()
{
    node *root = NULL;
    root = insertion(10, root);
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
    deletion(19, root);
    free(root);
    return 0;
}