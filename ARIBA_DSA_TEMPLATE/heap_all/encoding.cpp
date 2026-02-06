#include<bits/stdc++.h>
using namespace std;

struct Node{

    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f){
        ch = c;
        freq = f;
        left = nullptr;
        right = nullptr;
    }
};

struct minHeap{

    Node* a[200006];
    int cnt =0;

    void swim(int k){ //when child is smaller than parent node

        while(k>1 && a[k]->freq<a[k/2]->freq){
            swap(a[k],a[k/2]);
            k/=2;
        }
    }

    void sink(int k, int n){ //when parent is larger than child node
        
        if(n == 0) return;
        
        while(2*k<=n){
            int j = 2*k;
            if(j+1<=n && a[j+1]->freq< a[j]->freq) j++;
            if(a[j]->freq>=a[k]->freq) break;
            swap(a[k],a[j]);
            k=j;
        }
    }


    void push(Node* x) {
        cnt++;
        a[cnt]=x;
        swim(cnt);
    }

    void pop() {
        if(cnt==0){
            return;
        }
        swap(a[1],a[cnt]);
        cnt--;
        sink(1,cnt);
    }

    Node* peek() {
        if(cnt==0) return nullptr;
        return a[1];
    }

    int size() {
        return cnt;
    }

    void displayheap(){
    
        for(int i =1; i<=cnt;i++){
            cout<<a[i]->ch<<" "<<a[i]->freq<<"\n";
        }
    }

    void bottomUp(){

        if(cnt ==0) return;
        for(int i=cnt/2;i>=1;i--) sink(i,cnt);
    }
};

void inorder(Node* root){

    if(root == nullptr) return;
    inorder(root->left);
    if(root->ch !='\0') cout<<root->ch <<" "<<root->freq<<"\n";
    else cout<<root->freq<<"\n";
    inorder(root->right);
}

void postOrder(Node* root, map<char,string>&m, string code){

    if(root==nullptr) return;
    postOrder(root->left,m,code+'0');
    postOrder(root->right,m,code+'1');
    if(root->left==nullptr && root->right== nullptr){
        m.insert({root->ch,code});
        return;
    }
}

int main(){

    FILE* ptr_sample_text = fopen("sample_paragraph.txt","r");
    if(ptr_sample_text== NULL) cout<<"Error\n";
    FILE* ptr_input_text = fopen("input_paragraph.txt","w");
    if(ptr_input_text== NULL) cout<<"Error\n";
    char ch;
    while(fscanf(ptr_sample_text,"%c",&ch)!=EOF){
        if(('A'<=ch && ch<='Z')||('a'<=ch && ch<='z')||('0'<=ch && ch<='9')||(ch==' ')||(ch =='\n')){
           fputc(ch,ptr_input_text);
        }
    }
    fclose(ptr_input_text);
    fclose(ptr_sample_text);

    ptr_input_text = fopen("input_paragraph.txt","r");
    minHeap t;
    map<char,int>freq;
    while(fscanf(ptr_input_text,"%c",&ch)!=EOF){
        freq[ch]++;
    }
    for(auto m: freq){
        Node* exp = new Node(m.first,m.second);
        t.push(exp);
    }

    while(t.size()>=2){
        Node* l = t.peek();
        t.pop();
        Node* r = t.peek();
        t.pop();
        Node* newNode = new Node('\0',l->freq+r->freq);
        newNode->left =l;
        newNode->right = r;
        t.push(newNode);
    }
    Node* root = t.peek();

    map<char,string>preIndexCode;

    postOrder(root,preIndexCode,"");
    if (root->left == nullptr && root->right == nullptr) {
    preIndexCode[root->ch] = "0";
    }

    for(auto m: preIndexCode){
        cout<<m.first<<" "<<m.second<<"\n";
    }
    fclose(ptr_input_text);
    ptr_input_text = fopen("input_paragraph.txt","r");
    if(ptr_input_text==NULL) cout<<"Error";
    FILE* ptr_output_text = fopen("output_paragraph.txt","w");
    if(ptr_output_text==NULL) cout<<"Error";

    while(fscanf(ptr_input_text,"%c",&ch)!=EOF){
        string s = preIndexCode[ch];
        char c[s.size()+1];
        for(int i=0;i<s.size();i++){
            c[i]=s[i];
        }
        c[s.size()]='\0';
        fprintf(ptr_output_text,"%s",c);
    }

    fclose(ptr_input_text);
    fclose(ptr_output_text);
    return 0;
}