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
int maxheight = 0;
void find_height(Node_tree*temp,int height){
    if(!temp){
        maxheight = maxheight<height?height:maxheight;
        height--;
        return;
    }
    find_height(temp->left,height+1);
    find_height(temp->right, height+1);

}
int maxheight_opt(Node_tree*temp){
    if(!temp){
        return 0;
    }
    return 1+ max(maxheight_opt(temp->left),maxheight_opt(temp->right));
    

}



int main() {
  Node_tree root = Node_tree(5);
  root.left = new Node_tree(6);
  root.right = new Node_tree(7);
  root.left->left = new Node_tree(8);
  root.left->right = new Node_tree(9);
  root.left->right->left = new Node_tree(1);
  printTree(&root);
  find_height(&root,0);
  cout<<endl<<endl;
  cout<<maxheight;
  cout<<endl<<endl;
  cout<<maxheight_opt(&root);
  cout<<endl;

}