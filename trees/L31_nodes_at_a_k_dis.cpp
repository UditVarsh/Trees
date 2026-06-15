#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <queue>
#include <set>
#include <stack>
#include <type_traits>
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

vector<int> distanceK(Node_tree *root, Node_tree *target, int k) {
  // make the parent child relation
  //  make it by using a map
  //  then we traverse from that node in a graph manner as left,right and parent
  // use one vector for the visited node and a queue
  //  increse the cverage one by and count and the element in the last queue are
  //  the one which are 2 from it
  queue<Node_tree*>parent_q;
  unordered_map<Node_tree*, Node_tree*>map1;
  parent_q.push(root);
  while (!parent_q.empty()) {
        if(parent_q.front()->left){
            map1[parent_q.front()->left]=parent_q.front();
            parent_q.push(parent_q.front()->left);
        }
        if(parent_q.front()->right){
            map1[parent_q.front()->right]=parent_q.front();
            parent_q.push(parent_q.front()->right);

        }
        parent_q.pop();
    }
    set<Node_tree*>visited;
    queue<Node_tree*> q;
    int count = 0;
    q.push(target);
    while (count<=k) {
        if(q.front()->left){
            auto it= visited.find(q.front()->left);
            if(it==visited.end()){
                q.push(q.front()->left);
                visited.insert(q.front()->left);
            }
        }
        if(q.front()->right){
            auto it= visited.find(q.front()->right);
            if(it==visited.end()){
                q.push(q.front()->right);
                visited.insert(q.front()->right);
            }
        }
        if(map1[q.front()]){
            auto it = visited.find(map1[q.front()]);
            if(it==visited.end()){
                q.push(map1[q.front()]);
                visited.insert(map1[q.front()]);
            }
        }
        q.pop();
        count++;
    }
    vector<int>ans;
    while (!q.empty()) {
        ans.push_back(q.front()->data);
        q.pop();
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
  cout << endl << endl;
  cout << endl << endl;
  //   cout<<maxheight_opt(&root);
  cout << endl;
}
