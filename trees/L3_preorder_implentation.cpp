#include<bits/stdc++.h>
#include <cstddef>
#include <new>

using namespace std;

struct Node_tree{
    int data;
    Node_tree* left;
    Node_tree* right;

    Node_tree(int val){
        this->data = val;
        left = nullptr;
        right = nullptr;
    }

};

void preorder_traversal(Node_tree* Node){
    if(Node==nullptr){
        return;
    }
    cout<<Node->data<<" ";
    preorder_traversal(Node->left);
    preorder_traversal(Node->right);

}

int main(){
    Node_tree root =  Node_tree(5);
    root.left = new Node_tree(6);
    root.right = new Node_tree(7);
    root.left->left = new Node_tree(8);
    root.left->right = new Node_tree(9);
    root.left->right->left = new Node_tree(1);
    preorder_traversal(&root);
}