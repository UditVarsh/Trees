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

int maxheight_opt(Node_tree*temp){
    if(!temp){
        return 0;
    }
    return 1+ max(maxheight_opt(temp->left),maxheight_opt(temp->right));
    

}
pair<int,int> diameter_tree(Node_tree*temp,int maxi=0){// my methord of calculating diameter
    if(!temp){
        return {0,maxi};
    }
    pair left = diameter_tree(temp->left,maxi);
    pair right = diameter_tree(temp->right,maxi);
    int dia = max(max(left.second,right.second),left.first+right.first);
    if(dia>maxi)maxi= dia;
    return {(1+ max(left.first,right.first)),maxi};

}

int diameter_striver(Node_tree*temp,int*maxi){
    if(!temp)return 0;
    int left = diameter_striver(temp->left,maxi);
    int right = diameter_striver(temp->right, maxi);
    *maxi = max(*maxi,(left+right));
    return 1+max(left,right);
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
  cout<<diameter_tree(&root).first;
  cout<<endl<<endl;
//   cout<<maxheight_opt(&root);
  cout<<endl;

}