#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};
void traversal(Node* node, vector<int>&depth, int level){
  
  if(node == nullptr) return;
  
  traversal(node->left, depth, level+1);
  
  traversal(node->right, depth, level+1);
  
  depth[node->data] = level;
  
}

bool isPerfect(Node *root) {
    // code here
    
    vector<int>d(100001,0);
    traversal(root, d, 0);
    
    int cnt=1;
    int i;
    
    for(i=1;i<d.size();i++) if(d[i]!= 0) cnt++;
    
    int l= d[0];
    
    for(i=1;i<d.size();i++) if(d[i]>l) l= d[i];
    
    l++;
    
    if(cnt == (pow(2,l)-1)) return true;
    
    return false;
}
int main(){


    return 0;
}