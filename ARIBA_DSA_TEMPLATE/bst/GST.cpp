#include<bits/stdc++.h>
using namespace std;

struct Node{

    int val;
    Node* left;
    Node* right;

    Node(int new_val){
        val = new_val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertion(Node* root, int x){

    if(root==nullptr){
        Node* newNode = new Node(x);
        return newNode;
    }

    else if(x<=root->val) root->left = insertion(root->left,x);
    else if(x>root->val) root->right = insertion(root->right,x);
    return root;
}

void GST2_right(Node* root, vector<int>&a, int &sum){
    if(root == nullptr) return;

    GST2_right(root->right,a,sum);
    sum+=root->val;
    a[root->val]= sum - root->val;
    GST2_right(root->left,a,sum);
}

void GST2_left(Node* root, vector<int>&a, int &sum){
    if(root == nullptr) return;

    GST2_left(root->left,a,sum);
    sum+=root->val;
    a[root->val]= sum - root->val;
    GST2_left(root->right,a,sum);
}

void GST(Node* root, vector<int>&a){

    int sum =0;
    GST2_left(root,a,sum);

}

int main(){
    
    int n;
    cin>>n;

    Node* root = nullptr;

    while(n--){
        int x;
        cin>>x;
        root = insertion(root, x);
    }
    

    vector<int>right_sum(100001);
    vector<int>left_sum(100001);
    GST(root, left_sum);

    for(int i=1;i<=40;i++){
        cout<<left_sum[i]<<" ";
    }
    return 0;
}