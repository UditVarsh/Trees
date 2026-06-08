#include <bits/stdc++.h>
#include <cstddef>
#include <stack>
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

vector<int>iterative_postorder(Node_tree*root){//using the two stack approach for the postorder
  vector<int>ans;
  stack<Node_tree*>s1;
  stack<Node_tree*>s2;
  s1.push(root);
  Node_tree* temp;
  while(!s1.empty()) {
    temp = s1.top();
    s1.pop();
    s2.push(temp);
    if(temp->left){
      s1.push(temp->left);
    }
    if(temp->right){
      s1.push(temp->right);
    }
  }
  while (!s2.empty()) {
    ans.push_back(s2.top()->data);
    s2.pop();
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
  vector<int>ans = iterative_postorder(&root);
  for(int  i:ans)cout<<i<<" ";
  cout<<endl;

}
