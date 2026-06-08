#include <algorithm>
#include <bits/stdc++.h>
#include <cstddef>
#include <memory>
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
void findExtremes(Node_tree*root,int temp,int*rightMax,int*leftMin){
    if(!root){
        return;
    }
    if(temp>*rightMax){
        *rightMax = temp;
    }
    if(temp<*leftMin){
        *leftMin =temp;
    }
    findExtremes(root->left,temp-1,rightMax,leftMin);
    findExtremes(root->right, temp+1, rightMax, leftMin);
}
void traversal(Node_tree*root,vector<vector<int>>*ans,int temp){
    if(!root){
        return;
    }
    if((*ans)[temp].)
    (*ans)[temp].push_back(root->data);
    traversal(root->left,ans,temp-1);
    traversal(root->right, ans, temp+1);    
}

vector<vector<int>> verticalorder_traversal(Node_tree*root){
    int left= 0;
    int right =0;
    findExtremes(root,0,&right,&left);
    int total_size=abs(left)+right+1;
    vector<vector<int>>ans(total_size);
    traversal(root,&ans,abs(left));
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
    vector<vector<int>>ans=verticalorder_traversal(&root);
    for(vector<int>arr:ans){
        sort(arr.begin(),arr.end());
    }
    printLevel(ans);
  cout<<endl<<endl;
  
  cout<<endl<<endl;
//   cout<<maxheight_opt(&root);
  cout<<endl;

}