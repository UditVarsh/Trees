#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
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
bool identical_trees(Node_tree*temp1,Node_tree*temp2){
    if(!temp1&&!temp2){
        return 1;
    }
    if((!temp1&&temp2)||(temp1&&!temp2)){
        return 0;
    }
    if(temp1->data!=temp2->data){
        return 0;
    }
    bool left =identical_trees(temp1->left,temp2->left);
    bool right = identical_trees(temp1->right, temp2->right);
    if(!left||!right)return 0;
    return 1;

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
  int maxi=0;
  cout<<max_sum_path(&root,&maxi);
  cout<<endl<<endl;
  cout<<endl;

}
