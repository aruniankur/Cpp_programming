#include <iostream>
#include <stdc++.h>
using namespace std;
struct node {
    int data;
    struct node* left;
    struct node* right;
};

node* newnode(int data){
    node* temp = new node;
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void addnode(node* root, int child){
    if (child > root->data){
        if (root->right == NULL)
            root->right = newnode(child);
        else
            addnode(root->right, child);
    }
    else {
        if (root->left == NULL)
            root->left = newnode(child);
        else
            addnode(root->left, child);
    }
}

void inorderTraversal(node* root) {
    if (!root)
        return;
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(node* root) {
    if (!root)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(node* root) {
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

// Function for Level order tree traversal
void levelorderTraversal(node* root) {
    if (root == NULL)
        return;
    // Queue for level order traversal
    node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;
    while (front != rear) {
        node* temp = queue[front++];
        cout << temp->data << " ";
        // Push left child in the queue
        if (temp->left)
            queue[rear++] = temp->left;
        // Push right child in the queue
        if (temp->right)
            queue[rear++] = temp->right;
    }
}

bool findnumber(node* node, int num){
    if (!node) return false;
    if (node->data == num){
        cout << node->data << "->";
        return true;
    }
    if (node->data < num){
        cout << node->data << "->";
        return findnumber(node->right, num);
    }
    else {
        cout << node->data << "->";
        return findnumber(node->left, num);
    }
}

void deletenode(node* node, int num) {
    if(!node) return;
    
    return;
}

int main(){
    node* cl = newnode(12);
    node* cr = newnode(24);
    node root = {10, NULL, NULL};
    addnode(&root, 12);
    addnode(&root, 8);
    addnode(&root, 18);
    addnode(&root, 9);
    addnode(&root, 11);
    addnode(&root, 7);
    cout << root.data << endl;
    cout << root.right->data << endl;
    cout << root.left->data << endl;
    cout << findnumber(&root,17) << endl;
    return 0;
}