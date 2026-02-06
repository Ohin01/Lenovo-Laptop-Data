#include<bits/stdc++.h>
using namespace std;

int findCeil(vector<int>& arr, int x) {
    
    int l =0;
    int r =arr.size()-1;
    
    int ans =-1;
    while(l<=r){
        int m = l+(r-l)/2;
        if(arr[m]>=x){
            ans =m;
            r = m-1;
        }
        else l=m+1;
    }
    
    return ans;
}

int main(){
    return 0;
}