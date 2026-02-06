#include<bits/stdc++.h>
using namespace std;

struct Node{

    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// for depth
void traversal(Node* node, vector<int>&depth, int level){
  
  if(node == nullptr) return;
  
  traversal(node->left, depth, level+1);
  
  traversal(node->right, depth, level+1);
  
  depth[node->data] = level;
  
}

//for depth(another way)
void traversal5(Node* root, vector<int>&res){

  if(root->left!=nullptr){

    res[root->left->data] = res[root->data]+1;
    traversal5(root->left, res);
  }

  if(root->right!=nullptr){
    res[root->right->data] = res[root->data]+1;
    traversal5(root->right, res);
  }
}

//for height
void traversal1(Node* node, vector<int>&depth){

	if(node->left != nullptr){
     
      traversal1(node->left, depth);
       depth[node->data] = depth[node->left->data]+1;
      
    }
  
  	if(node->right != nullptr){
      
      traversal1(node->right, depth);
      depth[node->data] = max(depth[node->right->data]+1, depth[node->data]);
    }

}

//No. of nodes below each node
void traversal2(Node* node, vector<int>&depth){

	if(node->left != nullptr){
     
      traversal2(node->left, depth);
       depth[node->data] = depth[node->left->data]+1;
      
    }
  
  	if(node->right != nullptr){
      
      traversal2(node->right, depth);
      depth[node->data] = depth[node->right->data]+1 + depth[node->data];
    }

}
//No. of nodes on the left side of a node ??
void traversal3(Node* node, vector<int>&depth){

	if(node->left != nullptr){
     
      traversal3(node->left, depth);
      depth[node->data] = depth[node->left->data]+1+depth[node->data];
      
    }
  
  	if(node->right != nullptr){
      
      traversal3(node->right, depth);
      //depth[node->data] = depth[node->right->data]+1;
    }

}

//
void traversal4(Node* node, vector<int>&depth){

	if(node->left != nullptr){
     
      traversal4(node->left, depth);
      depth[node->data]+=depth[node->left->data];
      
    }
  
  	if(node->right != nullptr){
      
      traversal4(node->right, depth);
      depth[node->data]+=depth[node->right->data];
    }

}

int main(){

  Node* root = new Node(1);
  root->left = new Node(2);
  root->left->left = new Node(4);
  root->left ->right = new Node(5);
  root->left->right->right = new Node(6);
  root->right = new Node(3);
  root->right->right = new Node(7); 


  vector<int>height(8,0);
  vector<int>down_node(8,0); // no. of down nodes
  vector<int>up_node(8,0); // no of up nodes
  vector<int>left_node(8,0);
  vector<int>sum(8,0);
  int i;
  for(i=1;i<=7;i++) sum[i] = i; 
  
  traversal4(root,sum);
  for(i=1;i<=7;i++) sum[i]-= i; 
 // traversal2(root,down_node);

  // int l = down_node[0];
  // for(i=0;i<down_node.size();i++) if(down_node[i]>l) l = down_node[i];
  // int no_of_nodes = l+1;
  // for(i=1;i<down_node.size();i++) up_node[i] = l - down_node[i];

  for(int data : sum){
    cout<<data <<" ";
  }
  cout<<"\n";
  return 0;
}