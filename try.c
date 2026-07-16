#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node in BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);

    return root;
}

// Inorder Traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Find second highest node
void secondHighest(struct Node* root) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        printf("Second highest element not possible.\n");
        return;
    }

    struct Node *parent = NULL, *current = root;

    while (current->right != NULL) {
        parent = current;
        current = current->right;
    }

    // Case when largest node has left subtree
    if (current->left != NULL) {
        current = current->left;
        while (current->right != NULL)
            current = current->right;

        printf("Second highest node = %d\n", current->data);
    }
    else {
        printf("Second highest node = %d\n", parent->data);
    }
}

// Find minimum node
struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);

    else if (key > root->data)
        root->right = deleteNode(root->right, key);

    else {
        // Node with one or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Count nodes having common parent
int countCommonParentNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    int count = 0;

    if (root->left != NULL && root->right != NULL)
        count += 2;

    count += countCommonParentNodes(root->left);
    count += countCommonParentNodes(root->right);

    return count;
}

// Height of BST
int height(struct Node* root) {
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Count left side nodes of root
int countLeftNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    if (root->left == NULL)
        return 0;

    struct Node* temp = root->left;

    return 1 + countLeftNodes(temp) +
           countLeftNodes(temp->right);
}

// Count total nodes in subtree
int totalNodes(struct Node* root) {
    if (root == NULL)
        return 0;

    return 1 + totalNodes(root->left) + totalNodes(root->right);
}

int main() {
    struct Node* root = NULL;
    int choice, value;

    while (1) {
        printf("\n===== BINARY SEARCH TREE MENU =====\n");
        printf("1. Insert Node\n");
        printf("2. Display BST (Inorder)\n");
        printf("3. Find Second Highest Node\n");
        printf("4. Delete Node\n");
        printf("5. Count Nodes Having Common Parent\n");
        printf("6. Find Height of BST\n");
        printf("7. Count Nodes on Left Side of Root\n");
        printf("8. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                break;

            case 2:
                printf("BST Inorder Traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 3:
                secondHighest(root);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Node deleted successfully.\n");
                break;

            case 5:
                printf("Total nodes having common parent = %d\n",
                       countCommonParentNodes(root));
                break;

            case 6:
                printf("Height of BST = %d\n", height(root));
                break;

            case 7:
                if (root == NULL)
                    printf("Tree is empty.\n");
                else
                    printf("Total nodes on left side of root = %d\n",
                           totalNodes(root->left));
                break;

            case 8:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}