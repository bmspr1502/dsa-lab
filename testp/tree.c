    #include <stdio.h>
    #include <stdlib.h>

    //Time complexity is being written in the comments

    struct Node{
        int data;
        struct Node* left;
        struct Node* right;
    }typedef Node;

    //A function to create a new node and save data, has constant number of steps, O(1) time complexity
    Node *createNode(int data){
        Node *new = (Node *) malloc(sizeof(Node));
        if(!new){
            printf("\nOverflow.");
            return NULL;
        }

        new->data = data;
        new->left = NULL;
        new->right = NULL;
        return new;
    }

    /*  function to insert the node in BST format
        This function calls itself recursively until the appropriate location is found,
        It can call itself a max of h times, where h = height of the tree (at that point of time)
        Time complexity of inserNode() = O(h)
    */
    Node *insertNode(Node *root, int data){
        if(root == NULL)
            return createNode(data);

        if (data < root->data)
            root->left = insertNode(root->left, data);
        
        else if(data > root->data)
            root->right = insertNode(root->right, data);
        
        else if(data == root->data)
            printf("\nDuplicate entry found, aborting.");

        return root;
    }

    /*  Function to delete all the leaf nodes.
        It is traversing through all nodes, so the time complexity = O(n), n=number of nodes.
    */
    Node *deleteLeaves(Node *root){
        if(root==NULL)
            return NULL;

        if((root->left == NULL) && (root->right == NULL)){
            printf("\nDeleting %d.", root->data);
            free(root);
            return NULL;
        }

        root->left = deleteLeaves(root->left);
        root->right = deleteLeaves(root->right);

        return root;
    }

    /*  Function to display the tree in inorder
        Traverses through ll nodes, so time complexity = O(n)
    */
    void inorderDisplay(Node *root){
        if(root!=NULL){
            inorderDisplay(root->left);
            printf(" %d", root->data);
            inorderDisplay(root->right);
        }
    }

    //  Driver function
    int main(){
        Node *root = NULL;
        int temp,ch,count;
        do{
            printf("\n1.Insert Node\n2.Delete Leaves\n0.Exit");
            printf("\nEnter your choice(0-2): ");
            scanf("%d", &ch);

            if(ch==0){
                break;        
            }
            switch (ch)
            {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &temp);
                root = insertNode(root, temp);
                printf("Inorder status of tree = ");
                inorderDisplay(root);
                printf("\n");
                break;
            
            case 2:
                deleteLeaves(root);
                printf("\nInorder status of tree = ");
                inorderDisplay(root);
                printf("\n");
                break;

            default:
                break;
            }
        }while(1);
    
        return 0;
    }
