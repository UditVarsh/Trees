#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
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
vector<vector<int>>zig_zag(Node_tree*root){
    vector<vector<int>>ans;
    queue<Node_tree*>q;
    q.push(root);
    int count=0;
    while (!q.empty()) {
        vector<int>level={};
        vector<Node_tree*>temp = {};
        while (!q.empty()) {
            temp.push_back(q.front());
            q.pop();
        }
        for(Node_tree*i:temp){
            if(i->left)q.push(i->left);
            if(i->right)q.push(i->right);
        }
        if(count%2==0){
            for(int i=0;i<temp.size();i++){
                level.push_back(temp[i]->data);
            }
        }    
        else {
            for(int i = temp.size()-1;i>=0;i--){
                level.push_back(temp[i]->data);
            }
        } 
        count++;
        ans.push_back(level);
    }
    return ans;

}
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

  cout<<endl<<endl;
  vector<vector<int>>ans=zig_zag(&root);
  cout<<endl<<endl;
  printLevel(ans);
//   cout<<maxheight_opt(&root);
  cout<<endl;

}