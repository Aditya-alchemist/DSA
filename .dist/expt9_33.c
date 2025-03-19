#include <stdio.h>
#include <stdlib.h>
struct Node 
{
    int data;
    struct Node *l, *r;
};
struct Node* crtn(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->l = newNode->r = NULL;
    return newNode;
}
struct Node* ins(struct Node* root, int data) 
{
    if (root == NULL) return crtn(data);
    if (data < root->data)
        root->l = ins(root->l, data);
    else if (data > root->data)
        root->r = ins(root->r, data);
    return root;
}
void inO(struct Node* root) 
{
    if (root) 
    {
        inO(root->l);
        printf("%d ", root->data);
        inO(root->r);
    }
}
void preO(struct Node* root) 
{
    if (root) 
    {
        printf("%d ", root->data);
        preO(root->l);
        preO(root->r);
    }
}
void postO(struct Node* root) 
{
    if (root) 
    {
        postO(root->l);
        postO(root->r);
        printf("%d ", root->data);
    }
}
struct Node* search(struct Node* root, int key) 
{
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->l, key);
    return search(root->r, key);
}
struct Node* min(struct Node* root) 
{
    while (root && root->l)
        root = root->l;
    return root;
}
struct Node* max(struct Node* root) 
{
    while (root && root->r)
        root = root->r;
    return root;
}
struct Node* delt(struct Node* root) 
{
    if (root) 
    {
        root->l = delt(root->l);
        root->r = delt(root->r);
        free(root);
    }
    return NULL;
}
int main() 
{
    struct Node* root = NULL;
    int choice, data;
    do 
    {
        printf("\nBinary Search Tree Menu:\n");
        printf("----------------------------------------\n");
        printf("0. Quit\n1. Create\n2. In-Order Traversal\n3. Pre-Order Traversal\n4. Post-Order Traversal\n5. Search\n6. Find Smallest Element\n7. Find Largest Element\n8. Deletion of Tree\n");
        printf("----------------------------------------\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) 
        {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                root = ins(root, data);
                break;
            case 2:
                printf("In-Order Traversal: ");
                inO(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-Order Traversal: ");
                preO(root);
                printf("\n");
                break;
            case 4:
                printf("Post-Order Traversal: ");
                postO(root);
                printf("\n");
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &data);
                if (search(root, data))
                    printf("Element %d found in BST.\n", data);
                else
                    printf("Element %d not found in BST.\n", data);
                break;
            case 6:
                if (root)
                    printf("Smallest Element: %d\n", min(root)->data);
                else
                    printf("Tree is empty.\n");
                break;
            case 7:
                if (root)
                    printf("Largest Element: %d\n", max(root)->data);
                else
                    printf("Tree is empty.\n");
                break;
            case 8:
                root = delt(root);
                printf("Tree deleted successfully.\n");
                break;
            case 0:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } 
    while (choice != 0);
    return 0;
}