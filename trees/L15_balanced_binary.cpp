#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <cstdlib>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

struct Node_tree{
    int data;
    Node_tree* left;
    Node_tree* right;

    Node_tree(int data){
        this->data = data;
        left = nullptr;
        right =nullptr;
    }
};
void printTree(Node_tree *root, string indent = "", bool isLeft = true) {
  if (root == nullptr)
    return;

  // Print right subtree first
  printTree(root->right, indent + (isLeft ? "│   " : "    "), false);

  // Print current node
  cout << indent;

  if (isLeft)
    cout << "└── ";
  else
    cout << "┌── ";

  cout << root->data << endl;

  // Print left subtree
  printTree(root->left, indent + (isLeft ? "    " : "│   "), true);
}
int maxheight_opt(Node_tree*temp){
    if(!temp){
        return 0;
    }
    return 1+ max(maxheight_opt(temp->left),maxheight_opt(temp->right));
    
}
bool check_balanced(Node_tree*temp){//N
    if(!temp){
        return true;
    }
    int len_left = maxheight_opt(temp->left);
    int len_right = maxheight_opt(temp->right);
    int gap = abs(len_left-len_right);
    if(gap>1)return false;
    bool left = check_balanced(temp->left);
    bool right = check_balanced(temp->right);
    if(!left||!right)return false;
    return true; 
}
int checkBalanced(Node_tree*temp){
    if(!temp)return 0;
    int left  =checkBalanced(temp->left);
    int right = check_balanced(temp->right);
    if(left==-1||right==-1)return -1;
    if(abs(left-right)>1)return -1;
    return 1+max(left,right);
}



int main() {
  Node_tree root = Node_tree(5);
  root.left = new Node_tree(6);
  root.right = new Node_tree(7);
  root.left->left = new Node_tree(8);
  root.left->right = new Node_tree(9);
  root.left->right->left = new Node_tree(1);
  printTree(&root);
  cout<<endl<<endl;
  cout<<checkBalanced(&root);
  cout<<endl;

}