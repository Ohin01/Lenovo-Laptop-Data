#include<bits/stdc++.h>
using namespace std;

int binarysearch(vector<int> &arr, int k) {
    int l=0;
    int r = arr.size()-1;
    int index = -1;
    while(l<=r){
        int m = l + (r-l)/2;
        if(arr[m]==k){
            index = m;
            break;
        } 
        else if(arr[m]<k) l = m+1;
        else r = m-1;
    }
    
    if(index!=-1){
        
        while(arr[index]==k) index--;
        return index+1;
    }
    
    return -1;
}

int main(){
    return 0;
}