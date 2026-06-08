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
vector<int>find_top_view(Node_tree*root){
  queue<pair<Node_tree*, int>>q;
  map<int, int>map;
  int line=0;
  q.push({root,line});
  while (!q.empty()) {
    map[q.front().second] = q.front().first->data;
    if(q.front().first->left)q.push({q.front().first->left,q.front().second-1});
    if(q.front().first->right)q.push({q.front().first->right,q.front().second+1});
    q.pop();
  }
  vector<int>arr;
  for(pair<int,int>i:map){
    arr.push_back(i.second);
  }
  return arr;
}
int main() {
  Node_tree root = Node_tree(5);
  root.left = new Node_tree(6);
  root.right = new Node_tree(7);
  root.left->left = new Node_tree(8);
  root.left->right = new Node_tree(9);
  root.left->right->left = new Node_tree(1);
  printTree(&root);
  vector<int>arr = find_top_view(&root);

  cout<<endl<<endl;
  for(int i:arr)cout<<i<<" ";
  
  cout<<endl<<endl;
//   cout<<maxheight_opt(&root);
  cout<<endl;

}