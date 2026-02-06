#include<bits/stdc++.h>
using namespace std;

struct Queue{

    stack<int>s1;
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

    void dequeue1() {
        // Implement dequeue operation
        if(s1.empty()) return;
        int x = s1.top();
        s1.pop();
        
        if(s1.empty()) return;
        
        dequeue1();
        
        s1.push(x);
        
    }
    
    void dequeue(){
        dequeue1();
        cnt--;
    }

    int front() {
        // Implement front operation
        if(s1.empty()) return -1;
        stack<int>temp = s1;
        int num;
        while(temp.size()!=0){
            num = temp.top();
            temp.pop();
        }
        return num; 
    }

    int size() {
        // Implement size operation
        return cnt;
    }
};

int main(){
    return 0;
}