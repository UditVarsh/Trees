#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <queue>
#include <stack>
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
bool check_sym(Node_tree *root) {//this is a brute force approach
  queue<Node_tree *> q;
  Node_tree* s = new  Node_tree(INT_MIN); 
  q.push(root);
  while (!q.empty()) {
    vector<Node_tree *> temp = {};
    while (!q.empty()) {
      temp.push_back(q.front());
      q.pop();
    }
    for (Node_tree *i : temp) {
      if (i&&i!=s&&!i->left) {
        q.push(s);
      } else if(i->left) {
        q.push(i->left);
      }
      if (i&&i!=s&&!i->right) {
        q.push(s);
      } else if(i->right) {
        q.push(i->right);
      }
    }
    vector<int> ans;
    for (Node_tree *i : temp) {
     ans.push_back(i->data);
    }
    int first = 0;
    int last = ans.size() - 1;
    while (last >= first) {
      if (ans[last] != ans[first])
        return false;
      first++;
      last--;
    }
  }
  return true;
}
int main() {
  Node_tree root = Node_tree(1);

  root.left = new Node_tree(2);
  root.right = new Node_tree(2);

  root.left->left = new Node_tree(3);
  root.left->right = new Node_tree(4);

  root.right->left = new Node_tree(4);
  root.right->right = new Node_tree(3);

  root.left->left->left = new Node_tree(5);
  root.right->right->right = new Node_tree(5);

  root.left->right->right = new Node_tree(6);
  root.right->left->left = new Node_tree(6);
  printTree(&root);
  cout << endl << endl;
  cout << check_sym(&root);
  cout << endl << endl;
  //   cout<<maxheight_opt(&root);
  cout << endl;
}