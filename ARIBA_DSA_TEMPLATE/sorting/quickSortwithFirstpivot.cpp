#include<bits/stdc++.h>
using namespace std;

int pivot(int a[], int l , int r){

    int i = l+1;
    int j = r;

    while(i<=j){

        while(a[i]<a[l]){
            i++;
        }

        while(a[j]>a[l]){
            j--;
        }
        if(i<j) swap(a[i], a[j]);
    }
    swap(a[l], a[j]);
    return j;

}
void quickSort(int a[], int l, int r){

    if(l<r){

        int pi = pivot(a,l,r);
        quickSort(a,l,pi-1);
        quickSort(a,pi+1,r);

    }
}

int main(){

    int n;
    cin>>n;
    int i,j;

    int a[200005];

    for(i=0;i<n;i++) cin>>a[i];
    
    quickSort(a,0,n-1);

    for(i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}