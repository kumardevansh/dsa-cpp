#include<bits/stdc++.h>
using namespace std;

struct Node{
    // value of node
    int data;
    
    // pointer to left child node
    Node* left;
    // pointer to right child node
    Node* right;

    // constructor
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

// Pre order traversal - root left right
void preorder(Node* node){
    if(node==NULL) return;
    cout<<node->data<<" ";
    preorder(node->left);
    preorder(node->right);
}

// inorder traversal - left root right
void inorder(Node* node){
    if(node==NULL) return;
    inorder(node->left);
    cout<<node->data<<" ";
    inorder(node->right);
}

// postorder traversal - left right root
void postorder(Node* node){
    if(node==NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout<<node->data<<" ";
}

int main(){
    // creating new node for the root of binary tree
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);

    // right child for the left child of root node
    root->left->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right->left = new Node(6);

    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);

    cout<<"preorder  - ";
    preorder(root);
    cout<<endl;
    cout<<"inorder   - ";
    inorder(root);
    cout<<endl;
    cout<<"postorder - ";
    postorder(root);
}