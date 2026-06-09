#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <iostream>
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
int widthOfBinaryTree(Node_tree* root) {// this is a very bad approach as it is having a lot of overhead and thus O(2^n) is the time and space complexity

    queue<Node_tree*>q;
    int ans;
    Node_tree* sementic = new Node_tree(211);
    q.push(root);
    int max_width=0;
    while (!q.empty()) {
        vector<Node_tree*>temp={};
        vector<Node_tree*>temp1={};
        while (!q.empty()) {
            temp1.push_back(q.front());
            q.pop();
        }
        for(Node_tree*a:temp1){
            if(a->left)q.push(a->left);
            else if (!a->left)q.push(sementic);
            if(a->right)q.push(a->right);
            else if(!a->right) q.push(sementic);
        }
        while(!temp1.empty()&&temp1.back()==sementic){
            temp1.pop_back();
        }
        while(!temp1.empty()&&temp1.front()==sementic){
            temp1.erase(temp1.begin());
        }
        max_width = max_width<temp1.size()?temp1.size():max_width;
        if(temp1.size()==0){
            return max_width;
        }
    }
    return max_width;
}
int widthOfBinaryTree1(Node_tree*root){

    queue<pair<Node_tree*,long long unsigned int>>q;
    int max_width=0;
    q.push({root,0});
    while (!q.empty()) {
        vector<pair<Node_tree*,long long unsigned int>>temp={};
        while (!q.empty()) {
            temp.push_back(q.front());
            q.pop();
        }
        int width = temp.back().second-temp.front().second +1;
        if(max_width<width){
            max_width =width;
        }
        // int min=0;
        // for(pair<Node_tree*,int>i:temp){
        //     if(i.first->left){
        //         min = 2*(i.second)+1;
        //         break;
        //     }
        //     else if(i.first->right){
        //         min = 2*(i.second)+2;
        //         break;
        //     }
        //     else {
        //         continue;
        //     }
        // }
        long long offset = 0;
        for(pair<Node_tree*, int>i:temp){
            if(!temp.empty())offset =temp.front().second; 
            if(i.first->left)q.push({i.first->left,(2*(i.second))+1-offset});
            if(i.first->right)q.push({i.first->right,(2*(i.second))+2-offset});
        }
    }
    return max_width;
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
  int a =widthOfBinaryTree1(&root);
  cout<<endl<<endl;
  cout<<a;
//   cout<<maxheight_opt(&root);
  cout<<endl;

}