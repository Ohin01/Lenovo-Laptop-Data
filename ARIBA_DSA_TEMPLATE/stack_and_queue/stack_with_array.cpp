#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Stack{
    int n;
    Stack(int max) {

        n= max;
    }
    T a[200005];
    int cnt =0;
    bool isEmpty() {
        // check if the stack is empty
        return cnt ==0;
    }

    bool isFull() {
        // check if the stack is full
        return cnt == n;
    }

    void push(T x) {
        // inserts x at the top of the stack
        if(cnt == n) return;
        a[cnt]=x;
        cnt++;
    }

    void pop() {
        // removes an element from the top of the stack
        if(cnt == 0) return;
        cnt--;
    }

    T peek() {
        // Returns the top element of the stack
        if(cnt ==0) return -1;
        return a[cnt-1];
    }
};

int main(){
    return 0;
}

