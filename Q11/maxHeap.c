#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode *tree_ptr;
struct TreeNode {
    int data;
    tree_ptr left;
    tree_ptr right;
};

tree_ptr createNode(int value) {
    tree_ptr newNode = (tree_ptr)malloc(sizeof(*newNode));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

tree_ptr insert(tree_ptr root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value <= root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }
    return root;
}


tree_ptr deleteMax(tree_ptr root) {
    if (root == NULL)
        return NULL;
    if (root->right == NULL) {
        tree_ptr temp = root->left;
        free(root);
        return temp;
    }
    root->right = deleteMax(root->right);
    return root;
}

void displayHeap(tree_ptr root) {
    if (root != NULL) {
        displayHeap(root->right);
        printf("%d ", root->data);
        displayHeap(root->left);
    }
}

int main() {
    tree_ptr root = NULL;

    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 15);
    root = insert(root, 30);
    root = insert(root, 25);

    displayHeap(root);

    printf("\nDeleting the maximum element from the heap.\n");
    root = deleteMax(root);

    printf("\nHeap after deleting the maximum element:\n");
    displayHeap(root);

    return 0;
}
