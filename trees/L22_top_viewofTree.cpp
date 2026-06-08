#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cstddef>
#include <map>
#include <queue>
#include <stack>
#include <unordered_map>
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
void findExtremes(Node_tree*root,int temp,int *rightmax,int* left_min){
  if(!root){
    return;
  }
  if(*rightmax<temp){
    *rightmax =temp;
  }
  if(*left_min>=temp){
    *left_min = temp;
  }
  findExtremes(root->left, temp-1, rightmax, left_min);
  findExtremes(root->right, temp+1, rightmax, left_min);
}
void top_view(Node_tree*root,int temp,int* level,vector<pair<int, int>>*ans){
  if(!root){
    level--;
    return;
  }
  if((*ans)[temp].second>*level ){
    (*ans)[temp].first = root->data;
    (*ans)[temp].second = *level;
  }
  top_view(root->left, temp-1,level+1, ans);
  top_view(root->right, temp+1,level+1, ans);
  level--;
}

vector<int>find_topView(Node_tree*root){
  int rightmax  =0;
  int left_min = 0;
  findExtremes(root, 0, &rightmax, &left_min);
  int length = rightmax+abs(left_min)+1;
  vector<pair<int,int>>arr(length,{0,INT_MAX});
  int level = 0;
  top_view(root,abs(left_min),&level,&arr);
  vector<int>ans;
  for(pair<int,int>a:arr)ans.push_back(a.first);
  return ans;

}
// this is the approach 2 using the BFS which is a more relexed and easy one;
// use the queue and a map and queue is of a pair

vector<int>find_top_view(Node_tree*root){
  queue<pair<Node_tree*, int>>q;
  map<int, int>map;
  int line=0;
  q.push({root,line});
  while (!q.empty()) {
    if(map.find(q.front().second)==map.end()){
      map[q.front().second] = q.front().first->data;
    }
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

  vector<int> ans = find_topView(&root);
  vector<int>ans1 =find_top_view(&root);
  cout << endl << endl;
  for(int i:ans1)cout<<i<<" ";
  cout << endl << endl;

  //   cout<<maxheight_opt(&root);
  cout << endl;
}