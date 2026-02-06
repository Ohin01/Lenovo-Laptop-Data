#include<bits/stdc++.h>
using namespace std;

int mySqrt(int x) {
    long long l=1;
    long long r=x;
    long long m;
    while(l<=r){
        m = (l+r)/2;
        long long b= m*m;
        if(b==x) return m;
        else if(b<x) l=m+1;
        else r=m-1;
    }
    return l-1;
}

int main(){
    return 0;
}