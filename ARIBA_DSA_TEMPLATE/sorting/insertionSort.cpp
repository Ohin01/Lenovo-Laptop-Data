#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    int i,j;

    int a[200005];

    for(i=0;i<n;i++) cin>>a[i];
    
    for(i=1;i<n;i++){

        int key = a[i];
        j = i-1;

        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
        }

        a[j+1] = key;
    }

    for(i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}