#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>& arr, int target) {
    
    int l = 0;
    int r = arr.size()-1;
    int ans = arr.size();
    
    while(l<=r){
        int m = l+ (r-l)/2;
        
        if(arr[m]>= target){
            ans =m;
            r = m-1; 
        }
        
        else l = m+1;
    }
    
    return ans ;
}

int main(){
    return 0;
}