#include<bits/stdc++.h>
using namespace std;

int cntDigit(int n){
    int cnt =0;
    while(n>0){
        n/=10;
        cnt++;
    }
    return cnt;
}

void counting_sort_with_stable_order(int a[], int n, int p){

    int c = (int)pow(10,p);
    int d = (int)pow(10,p-1);
    int l = a[0];
    int i,j;
    for(i=0;i<n;i++) if(a[i]>l) l= a[i];
    int count[l+1];
    for(i=0;i<l+1;i++) count[i]=0;
    for(i=0;i<n;i++) count[(a[i]%c)/d]++;
    for(i=1;i<=l;i++) count[i]+=count[i-1];
    
    int res[n];
    for(i=0;i<n;i++) res[i]= 0;

    for(i=n-1;i>=0;i--){
        res[count[(a[i]%c)/d]-1] = a[i];
        count[(a[i]%c)/d]--;
    }

    for(i=0;i<n;i++){
        a[i]= res[i];
    }
}


void radixSort(int a[], int n){

    int l = a[0];
    int i;
    for(i=0;i<n;i++) if(a[i]>l) l = a[i];
    int cnt = cntDigit(l);
    for(i=1;i<=cnt;i++){
        counting_sort_with_stable_order(a,n,i);
    }

}

int main(){

    int n;
    cin>>n;
    int a[200005];
    int i;
    for(i=0;i<n;i++) cin>>a[i];
    radixSort(a,n);
    for(i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    
    return 0;
}