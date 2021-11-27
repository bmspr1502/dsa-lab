#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *leftChild;
    struct node *rightChild;
} typedef node;

node *root = NULL;

//function to create dynamically allocate the node
node *newNode(int dat)
{
    node *new = (node *)malloc(sizeof(node));
    new->data = dat;
    new->leftChild = NULL;
    new->rightChild = NULL;
    return new;
}

//function to insert the node to the tree
node *insert(struct node *ptr, int data)
{
    if (ptr == NULL)
        return newNode(data);

    if (data < ptr->data)
        ptr->leftChild = insert(ptr->leftChild, data);

    else if (data > ptr->data)
        ptr->rightChild = insert(ptr->rightChild, data);

    return ptr;
}

//inorder traversal of the tree
void inorderDisplay(node *ptr)
{

    if (ptr != NULL)
    {
        inorderDisplay(ptr->leftChild);
        printf(" %d", ptr->data);
        inorderDisplay(ptr->rightChild);
    }
}

//to find the inorder successor of the given subtree (minimum value of the subtree)
node *inorderSuccessor(node *ptr)
{

    node *curr = ptr;
    while (curr && curr->leftChild != NULL)
    {
        curr = curr->leftChild;
    }
    return curr;
}

//function to delete the node
node *deleteNode(node *ptr, int data)
{

    if (ptr == NULL)
        return ptr;

    if (data < ptr->data)
        ptr->leftChild = deleteNode(ptr->leftChild, data);

    else if (data > ptr->data)
        ptr->rightChild = deleteNode(ptr->rightChild, data);

    else
    {

        if (ptr->leftChild == NULL)
        {

            node *temp = ptr->rightChild;
            free(ptr);
            return temp;
        }
        else if (ptr->rightChild == NULL)
        {

            node *temp = ptr->leftChild;
            free(ptr);
            return temp;
        }

        else
        {

            node *temp = inorderSuccessor(ptr->rightChild);
            ptr->data = temp->data;
            ptr->rightChild = deleteNode(ptr->rightChild, temp->data);
        }
    }

    return ptr;
}

//modification function to count the elements
void countelem(node *ptr, int *count)
{

    if (ptr != NULL)
    {
        countelem(ptr->leftChild, count);
        (*count)++;
        countelem(ptr->rightChild, count);
    }
}

//driver function
int main()
{

    int temp, ch, count;

    do
    {
        printf("\n1.Insert\n2.Display\n3. Delete\n4.Count the nodes\n0.Exit");
        printf("\nEnter your choice(0-4): ");
        scanf("%d", &ch);
        if (ch == 0)
        {
            break;
        }
        switch (ch)
        {
        case 1:
            printf("\nEnter the data: ");
            scanf("%d", &temp);

            if (root == NULL)
                root = insert(root, temp);
            else
                insert(root, temp);

            break;

        case 2:
            printf("\nThe inorder display of the tree: ");
            inorderDisplay(root);
            break;

        case 3:
            printf("\nEnter the element to delete: ");
            scanf("%d", &temp);
            root = deleteNode(root, temp);
            break;

        case 4:
            count = 0;
            countelem(root, &count);
            printf("\nThe number of nodes in the BST is : %d\n", count);

        default:
            break;
        }

    } while (1);

    return 0;
}