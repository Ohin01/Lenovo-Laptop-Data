#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int i,j;

    int a[200005];

    for(i=0;i<n;i++) cin>>a[i];
    
    for(i=0;i<n;i++){
        int index =i;
        for(j=i;j<n;j++){
            if(a[j]<a[index]) index = j;
        }
        int temp = a[index];
        a[index] = a[i];
        a[i] =temp;
    }

    for(i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}