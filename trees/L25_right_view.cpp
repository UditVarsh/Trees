#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <map>
#include <queue>
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
vector<int> rightView(Node_tree*root){
    if(!root){
        return {};
    }
    queue<pair<Node_tree*,int>>q;
    map<int, int>map;
    q.push({root,0});
    int level=0;
    while (!q.empty()) {
        vector<Node_tree*>temp ={};
        while (!q.empty()) {
            temp.push_back(q.front().first);
            q.pop();
        }
        if(!temp.empty())map[level]=temp.back()->data;
        level++;
        for(Node_tree*i:temp){
            if(i->left)q.push({i->left,level});
            if(i->right)q.push({i->right,level});
        }
    }
    vector<int>ans;
    for(pair<int,int>i:map){
        ans.push_back(i.second);
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
  cout<<endl<<endl;
  vector<int>ans = rightView(&root);
  cout<<endl<<endl;
  for(int i:ans)cout<<i<<" ";
//   cout<<maxheight_opt(&root);
  cout<<endl;

}