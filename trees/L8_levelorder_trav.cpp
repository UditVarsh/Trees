#include <bits/stdc++.h>
#include <queue>
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
vector<vector<int>> level_traversal(Node_tree *root) {
    queue<Node_tree*>level_element;
    
    vector<vector<int>>level_traversed;
    if(!root){
        return level_traversed ;
    }
    level_element.push(root);
    while(!level_element.empty()){
      vector<int>q={};
      vector<Node_tree*>temp ={};
      while(!level_element.empty()){
        temp.push_back(level_element.front());
        q.push_back(level_element.front()->data);
        level_element.pop();
      }
      level_traversed.push_back(q);
      for(Node_tree*i:temp){
        if(i->left!=nullptr){
          level_element.push(i->left);
        }
        if(i->right!=nullptr){
          level_element.push(i->right);
        }
      }
    }
    return level_traversed;

}// not the best approach uses extra DS to keep the track of the elements where as we can use the queues internal property


void printLevel(vector<vector<int>>arr){
  int count = 1;
for(vector<int>i:arr){
    cout<<"Level"<<count<<": ";
    for(int k:i){
      cout<<k<<" ";
  }
    cout<<endl;
    count++;
  }
}

int main() {
  Node_tree root = Node_tree(5);
  root.left = new Node_tree(6);
  root.right = new Node_tree(7);
  root.left->left = new Node_tree(8);
  root.left->right = new Node_tree(9);
  root.left->right->left = new Node_tree(1);
  printTree(&root);
  vector<vector<int>>arr = level_traversal(&root);
  printLevel(arr);


}