#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <stack>
#include <unistd.h>
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
void boundry_travrsal(Node_tree*temp,vector<int>*arr,bool *checkLeft){
    if(!temp){
        return;
    }
    if(temp->left&&temp->right&&*checkLeft){
        arr->push_back(temp->data);
    }
    if(!temp->left&&!temp->right){
        *checkLeft=0;
        arr->push_back(temp->data);
        return;
    }
    boundry_travrsal(temp->left,arr,checkLeft);
    boundry_travrsal(temp->right, arr, checkLeft);
}
void addright(Node_tree*temp,vector<int>*arr){
    if(!temp->left&&!temp->right){
        return;
    }
    addright(temp->right, arr);
    arr->push_back(temp->data);
}
int main() {
Node_tree root = Node_tree(1);

root.left = new Node_tree(2);
root.right = new Node_tree(3);

root.left->left = new Node_tree(4);
root.left->right = new Node_tree(5);

root.right->left = new Node_tree(6);
root.right->right = new Node_tree(7);

root.left->right->left = new Node_tree(8);
root.left->right->right = new Node_tree(9);

printTree(&root);

  cout<<endl<<endl;
  
  cout<<endl<<endl;
//   cout<<maxheight_opt(&root);
vector<int>arr={};
bool left = 1;
boundry_travrsal(&root, &arr, &left);
addright(root.right, &arr);
for(int i:arr){
    cout<<i<<" ";
}
cout<<endl;

}