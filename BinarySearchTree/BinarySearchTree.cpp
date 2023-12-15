#include <iostream>

struct tree 
{
    int item;
    tree *parent;
    tree *left;
    tree *right;
};

tree *search_tree(tree *t, int data)
{
    if (t == NULL)
        return (NULL);
    if (t->item == data)
        return (t);
    if (data < t->item)
        return (search_tree(t->left, data));
    else 
        return (search_tree(t->right, data));
}

tree *find_minimum(tree *t)
{
    tree *min;

    if (t == NULL)
        return (NULL);
    min = t;
    while (min->left != NULL)
        min = min->left;
    return (min);
}

tree *find_maximum(tree *t)
{
    tree *max;

    if (t == NULL)
        return (NULL);
    max = t;
    while (max->right != NULL)
        max = max->right;
    return (max);
}

void traverse_tree(tree *t)
{
    if (t != NULL)
    {
        traverse_tree(t->left);
        std::cout << t->item << " ";
        traverse_tree(t->right);
    }
}

void insert_tree(tree **t, int data, tree *parent)
{
    tree *temp;

    if (*t == NULL)
    {
        temp = new tree();
        temp->item = data;
        temp->left = temp->right = NULL;
        temp->parent = parent;
        *t = temp;
        return;
    }
    if (data < (*t)->item)
        insert_tree(&((*t)->left), data, *t);
    else
        insert_tree(&((*t)->right), data, *t);
}

int main()
{
    tree *myTree = NULL;
    insert_tree(&myTree, 5, myTree);
    insert_tree(&myTree, -2, myTree);
    insert_tree(&myTree, 0, myTree);
    insert_tree(&myTree, 3, myTree);
    insert_tree(&myTree, 6, myTree);
    insert_tree(&myTree, -9, myTree);
    insert_tree(&myTree, 99, myTree);
    insert_tree(&myTree, -34, myTree);
    insert_tree(&myTree, -42, myTree);
    insert_tree(&myTree, 42, myTree);
    std::cout << myTree->item << std::endl;
    traverse_tree(myTree);
    tree *ptr42 = search_tree(myTree, 42);
    std::cout << ptr42 << " " << ptr42->item << " " << ptr42->left << " " << ptr42->right << std::endl;
    std::cout << find_maximum(myTree)->item << std::endl;
    std::cout << find_minimum(myTree)->item << std::endl;    
    traverse_tree(myTree);
    return (0);
}
