#include<stdio.h>
#include<stdlib.h>

typedef struct node *tree_ptr;
typedef struct node{
    int data;
    tree_ptr left_child, right_child;
}node;


void inorder(tree_ptr ptr){
    if(ptr){
        inorder(ptr->left_child);
        printf("%d ", ptr->data);
        inorder(ptr->right_child);
    }
}

void preorder(tree_ptr ptr){
    if(ptr){
        printf("%d ", ptr->data);
        preorder(ptr->left_child);
        preorder(ptr->right_child);
    }
}

void postorder(tree_ptr ptr){
    if(ptr){
        postorder(ptr->left_child);
        postorder(ptr->right_child);
        printf("%d ", ptr->data);                             
    }
}


tree_ptr newNode(int item){
    tree_ptr temp = (tree_ptr)malloc(sizeof(*temp));
    temp->data = item;
    temp->left_child = temp->right_child = NULL;
    return temp;
}

tree_ptr insert(tree_ptr temp , int key){
    if(temp==NULL){
        return newNode(key);
    }
    else if(key < temp->data){
        temp->left_child = insert(temp->left_child, key);
    }
    else if(key > temp->data){
        temp->right_child = insert(temp->right_child, key);
    }
    return temp;
}

int main(){
    tree_ptr root = NULL;
    root = insert(root , 50);
    insert(root , 45);
    insert(root , 78);
    insert(root , 3647);
    insert(root , 11);
    insert(root , 5);

    printf("\nPreorder: \n");
    preorder(root);
    printf("\nPostorder: \n");
    postorder(root);
    printf("\nInorder: \n");
    inorder(root);

    return 0;
}
