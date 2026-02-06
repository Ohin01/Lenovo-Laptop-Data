#include<bits/stdc++.h>
using namespace std;

struct twoStack{

    int cnt1;
    int cnt2;
    int a[101];
    twoStack() {cnt1 =0; cnt2 =100;}

    // Function to push an integer into the stack1.
    void push1(int x) {
        // code here
        if(cnt1 < cnt2 -1){a[cnt1]=x;
        cnt1++;}
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        // code here
        if(cnt1 < cnt2 -1){a[cnt2]=x;
        cnt2--;}
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        // code here
        if(cnt1==0) return -1;
        int temp = a[cnt1-1];
        cnt1--;
        return temp;
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        // code here
        if(cnt2==100) return -1;
        int temp = a[cnt2+1];
        cnt2++;
        return temp;
    }
};


int main(){
    return 0;
}
