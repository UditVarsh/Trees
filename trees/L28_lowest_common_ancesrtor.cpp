#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <stack>
#include <stdexcept>
#include <utility>
#include <vector>

using namespace std;

struct Node_tree {
  int data;
  Node_tree *left;
  Node_tree *right;

  Node_tree(int data) {
    this->data = data;
    left = nullptr;
    right = nullptr;
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
void rootToNode_path(Node_tree *root, vector<Node_tree*>*a,Node_tree*check,bool*isFind) {
  if (!root) {
    return;
  }
  if (root==check) {
    (*a).push_back(root);
    *isFind=1;
    return;
  }
  (*a).push_back(root);
  rootToNode_path(root->left, a, check, isFind);
   if(*isFind==1){
    return;
  }
  rootToNode_path(root->right, a, check, isFind);
   if(*isFind==1){
    return;
  }
  (*a).pop_back();
}
Node_tree*lowestCommonAncestor(Node_tree* root, Node_tree* p, Node_tree* q){
    vector<Node_tree*>path1;
    vector<Node_tree*>path2;
    bool isfind1=0,isfind2=0;
    rootToNode_path(root, &path1, p, &isfind1);
    rootToNode_path(root, &path2, q, &isfind2);
    Node_tree*common;
    int i=0;
    int j=0;
    while (true) {
        if((i<path1.size()&&j<path2.size())&&path1[i]==path2[j])common=path1[i];
        else break;
        i++;
        j++;
    }
    return common;
}
Node_tree*lowestCommonAncestor1(Node_tree*root,Node_tree*p,Node_tree*q){
    if()
}

int main() {
  Node_tree root = Node_tree(5);
  root.left = new Node_tree(6);
  root.right = new Node_tree(7);
  root.left->left = new Node_tree(8);
  root.left->right = new Node_tree(9);
  root.left->right->left = new Node_tree(1);
  Node_tree*first =root.left->left;
  Node_tree*sec = root.left->right->left;
  printTree(&root);
  vector<Node_tree*>ans={};
  bool isfind = 0;
  Node_tree*LCA =lowestCommonAncestor(&root,first,sec);
  cout << endl << endl;
  cout << LCA->data;
  cout << endl << endl;
  //   cout<<maxheight_opt(&root);
  cout << endl;
}