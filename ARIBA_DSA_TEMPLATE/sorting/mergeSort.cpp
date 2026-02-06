#include<bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r){

    int n1 = m-l+1;
    int n2 = r-m;

    int L[n1];
    int M[n2];

    for(int p =0; p<n1; p++) L[p] = a[p+l];
    for(int q =0; q<n2; q++) M[q] = a[m+1+q];

    int i=0, j=0, k=l;

    while(i<n1 && j<n2){
        if(L[i]<=M[j]){
            a[k] = L[i];
            i++;
        }
        else{
            a[k] = M[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        a[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int l, int r){

    if(l<r){
        int m = (l+r)/2;
        mergeSort(a,l,m);
        mergeSort(a,m+1, r);
        merge(a,l,m,r);
    }
}


int main(){

    int n;
    cin>>n;
    int i,j;

    int a[200005];

    for(i=0;i<n;i++) cin>>a[i];
    
    mergeSort(a,0,n-1);

    for(i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}
