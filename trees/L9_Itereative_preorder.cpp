#include <bits/stdc++.h>
#include <queue>
#include <stack>
#include <type_traits>
#include <vector>
using namespace std;

struct Node_tree {
  int data;
  Node_tree *left;
  Node_tree *right;

  Node_tree(int val) {
    this->data = val;
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
vector<int> iterative_preorder(Node_tree*root){//RootLR
  stack<Node_tree*>s;
  Node_tree*temp;
  vector<int>ans;
  s.push(root);
  while (!s.empty()) {
    temp = s.top();
    ans.push_back(temp->data);
    s.pop();
    if(temp->right)s.push(temp->right);
    if(temp->left)s.push(temp->left);
  }
  return ans;
}
int main() {
  Node_tree root = Node_tree(5);
  root.left = new Node_tree(6);
  root.right = new Node_tree(7);
  root.left->left = new Node_tree(8);
  root.left->right = new Node_tree(9);
  root.left->right->left = new Node_tree(1);
  printTree(&root);
  vector<int>ans = iterative_preorder(&root);
  for(int  i:ans)cout<<i<<" ";
  cout<<endl;

}

