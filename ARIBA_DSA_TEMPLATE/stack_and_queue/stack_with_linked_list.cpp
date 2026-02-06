#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

template<typename T>
struct Stack{
    Node* root;
    int cnt;
    Stack() {
        // Initialize your data members
        root = nullptr;
        cnt =0;
    }

    bool isEmpty() {
        // check if the stack is empty
        return cnt==0;
    }

    void push(T x) {
        // Adds an element x at the top of the stack
        if(root == nullptr){
            root = new Node(x);
            cnt++;
            return;
        }
        Node* newNode = new Node(x);
        newNode -> next = root;
        
        Node* temp = root;
        root = newNode;
        newNode = root;
        cnt++;
    }

    void pop() {
        // Removes the top element of the stack
        if(cnt==0) return;
        root = root->next;
        cnt--;
    }

    T peek() {
        // Returns the top element of the stack
        // If stack is empty, return -1
        if(cnt==0) return -1;
        return root->data;
    }

    int size() {
        // Returns the current size of the stack.
        return cnt;
    }
};

int main(){
    return 0;
}

