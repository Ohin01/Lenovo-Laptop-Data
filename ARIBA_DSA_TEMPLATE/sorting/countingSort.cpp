#include<bits/stdc++.h>
using namespace std;

void counting_sort_with_stable_order(int a[], int n){

    int l = a[0];
    int i,j;
    for(i=0;i<n;i++) if(a[i]>l) l= a[i];
    int count[l+1];
    for(i=0;i<l+1;i++) count[i]=0;
    for(i=0;i<n;i++) count[a[i]]++;
    for(i=1;i<=l;i++) count[i]+=count[i-1];
    
    int res[n];
    for(i=0;i<n;i++) res[i]= 0;

    for(i=n-1;i>=0;i--){
        res[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }

    for(i=0;i<n;i++){
        a[i]= res[i];
    }
}


void counting_sort_without_stable_order(int a[], int n){

    int l = a[0];
    int i,j;
    for(i=0;i<n;i++) if(a[i]>l) l= a[i];
    int count[l+1];
    for(i=0;i<l+1;i++) count[i]=0;
    for(i=0;i<n;i++) count[a[i]]++;
    for(i=0;i<l+1;i++){
        if(count[i]!=0){
            while(count[i]!=0){
                cout<<i<<" ";
                count[i]--;
            }
        }
    }
    cout<<"\n";
}


int main(){

    int n;
    cin>>n;
    int i,j;

    int a[200005];

    for(i=0;i<n;i++) cin>>a[i];
    
    counting_sort_with_stable_order(a,n);
    for(i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}