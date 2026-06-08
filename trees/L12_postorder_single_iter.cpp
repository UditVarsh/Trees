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
vector<int>iter_post_1stack(Node_tree*root){
    vector<int>ans;
    
    stack<pair<Node_tree*, int>>s{};
    pair<Node_tree*,int>temp = {root,0};
    s.push(temp);
    while (true) {
        if(temp.first->left!=nullptr&&temp.second==0){
            s.top().second =1;
            temp = {temp.first->left,0};
            s.push(temp);
        }
        else if(temp.first->right!=nullptr&&temp.second==1){
            s.top().second = 2;
            temp = {temp.first->right,0};
            s.push(temp);
        }
        else {
            ans.push_back(s.top().first->data);
            s.pop();
            if(!s.empty())temp = s.top();
            else break;
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
  vector<int>ans = iter_post_1stack(&root);
  for(int  i:ans)cout<<i<<" ";
  cout<<endl;
}