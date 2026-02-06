#include<bits/stdc++.h>
using namespace std;

struct Queue{

    stack<int>s1;
    stack<int>s2;
    int cnt;
    Queue() {
        // Initialize your data members
        cnt =0;
    }

    void enqueue(int x) {
        // Implement enqueue operation
        s1.push(x);
        cnt++;
    }

    void dequeue() {
        // Implement dequeue operation
        if(s1.empty()) return;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        s2.pop();
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        cnt--;
    }

    int front() {
        // Implement front operation
        if(s1.empty()) return -1;
        while(!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        
        int temp = s2.top();
        
        while(!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return temp; 
    }

    int size() {
        // Implement size operation
        return cnt;
    }
};

int main(){
    return 0;
}