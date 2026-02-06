#include<bits/stdc++.h>
using namespace std;

template<typename T>
struct Stack{
    int n;
    T a[200005];
    int cnt =0;
    Stack(int max) {

        n= max;
    }
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
        if(cnt ==0) return '#';
        return a[cnt-1];
    }
};

bool isBalanced(string& s) {
    // code here
    Stack<char>st(1000001);
    for(int i=0;i<s.size();i++){
        if((st.peek()=='(' && s[i]==')')||(st.peek()=='{' && s[i]=='}')||(st.peek()=='[' && s[i]==']')){
            st.pop();
            continue;
        }
        st.push(s[i]);
    }
    if(st.isEmpty()) return true;
    return false;
}

int main(){
    return 0;
}