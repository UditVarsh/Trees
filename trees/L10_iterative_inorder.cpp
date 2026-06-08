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
vector<int>iterative_inorder(Node_tree*root){
    stack<Node_tree*>s;
    vector<int>ans;
    Node_tree*temp =root;
    while(true){
        if(temp!=nullptr){
            s.push(temp);
            temp = temp->left;
        }
        else{
            if(s.empty())break;
            ans.push_back(s.top()->data);
            temp = s.top()->right;
            s.pop();
        }
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
  vector<int>ans = iterative_inorder(&root);
  for(int  i:ans)cout<<i<<" ";
  cout<<endl;

}
