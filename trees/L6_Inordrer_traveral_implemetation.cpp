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
void printTree(Node_tree* root, string indent = "", bool isLeft = true)
{
    if(root == nullptr)
        return;

    // Print right subtree first
    printTree(root->right, indent + (isLeft ? "│   " : "    "), false);

    // Print current node
    cout << indent;

    if(isLeft)
        cout << "└── ";
    else
        cout << "┌── ";

    cout << root->data << endl;

    // Print left subtree
    printTree(root->left, indent + (isLeft ? "    " : "│   "), true);
}

void inorder_traveral(Node_tree* Node){
    if(Node==nullptr){
        return;
    }
    inorder_traveral(Node->left);
    cout<<Node->data<<" ";
    inorder_traveral(Node->right);
}

int main(){
    Node_tree root = Node_tree(1);

  root.left = new Node_tree(2);
  root.right = new Node_tree(3);

  // Level 2
  root.left->left = new Node_tree(4);
  root.left->right = new Node_tree(5);
  root.right->left = new Node_tree(6);
  root.right->right = new Node_tree(7);

  // Level 3
  root.left->left->left = new Node_tree(8);
  root.left->left->right = new Node_tree(9);

  root.left->right->left = new Node_tree(10);
  root.left->right->right = new Node_tree(11);

  root.right->left->left = new Node_tree(12);
  root.right->left->right = new Node_tree(13);

  root.right->right->left = new Node_tree(14);
  root.right->right->right = new Node_tree(15);

  // Level 4
  root.left->left->left->left = new Node_tree(16);
  root.left->left->left->right = new Node_tree(17);

  root.left->left->right->left = new Node_tree(18);
  root.left->left->right->right = new Node_tree(19);

  root.left->right->left->left = new Node_tree(20);
  root.left->right->left->right = new Node_tree(21);

  root.left->right->right->left = new Node_tree(22);
  root.left->right->right->right = new Node_tree(23);

  root.right->left->left->left = new Node_tree(24);
  root.right->left->left->right = new Node_tree(25);

  root.right->left->right->left = new Node_tree(26);
  root.right->left->right->right = new Node_tree(27);

  root.right->right->left->left = new Node_tree(28);
  root.right->right->left->right = new Node_tree(29);

  root.right->right->right->left = new Node_tree(30);
  root.right->right->right->right = new Node_tree(31);
    printTree(&root);
    inorder_traveral(&root);
}