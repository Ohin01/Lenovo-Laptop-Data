#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int cnt1 =0;
int cnt2=0;
int cnt3=0;

void BubbleSort(int a[], int n){

    int i,j;
    int cmp = 0;
    int swap= 0;
    for(i=0;i<n;i++){
        for(j=i;j<n;j++){
            if(a[i]>a[j]){
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
                swap++;
            }
            cmp++;
        }
    }

    cout<<"Sorted array: ";
    for(int p=0;p<n;p++) cout<<a[p]<<' ';
    cout<<"\n";
    cout<<"Bubble sort: \n";
    cout<<"Compares: "<< cmp<<"\n";
    cout<<"Swaps: "<<swap<<"\n";
}

void InsertionSort(int a[], int n){

    int i,j,key;
    int swap =0;
    for(i=1;i<n;i++){

        key = a[i];
        j= i-1;
        while(j>=0 && a[j]>key){
            a[j+1] = a[j];
            j--;
            swap++;
        }
        a[j+1] = key;
    }
    cout<<"Insertion sort: ";
    // for(int p=0;p<n;p++) cout<<a[p]<<' ';
    // cout<<"\n";
    cout<<"Swaps: "<<swap<<"\n";
}

void SelectionSort(int a[], int n){
    
    int i,j;
    int index;
    int cmp=0;
    int swap =0;

    for(i=0;i<n;i++){
        
        index = i;
        for(j=i;j<n;j++) {if(a[j]<a[index]) index = j; cmp++;}
        int temp = a[index];
        a[index] = a[i];
        a[i] = temp;
        swap++;
    }

    cout<<"Selection sort: ";
    // for(int p=0;p<n;p++) cout<<a[p]<<' ';
    // cout<<"\n";
    cout<<"Compares: "<< cmp<<"\n";
    cout<<"Swaps: "<<swap<<"\n";
}

void merge(int a[], int l, int m, int r){

    int n1 = m-l+1;
    int n2 = r-m;

    int L[200005], M[200005];

    for(int p =0 ;p<n1; p++) L[p] = a[l+p];
    for(int q =0; q<n2; q++) M[q] = a[m+1+q];

    int i=0, j=0, k=l;

    while(i<n1 && j<n2){

        if(L[i]<=M[j]){

            a[k]= L[i];
            i++;
            cnt2++;
        }

        else{

            a[k]= M[j];
            j++;
            cnt2++;
        }

        k++;
        cnt++;
    }

    while(i<n1){
        a[k] = L[i];
        i++;
        k++;
        cnt2++;
    }

    while(j<n2){

        a[k] = M[j];
        j++;
        k++;
        cnt2++;
    }
}

void MergeSort(int a[],int n,  int l, int r){

    if(l>=r){
        return;
    }

    int mid = (l+r)/2;
    MergeSort(a,n,l,mid);
    MergeSort(a,n,mid+1,r);
    merge(a,l,mid,r);

}

void showMergeSort(int a[], int n, int l, int r){

    MergeSort(a,n,l,r);
    cout<<"Merge sort: ";
    // for(int p=0;p<n;p++) cout<<a[p]<<' ';
    // cout<<"\n";
    cout<<"Compares: "<<cnt<<"\n";
    cout<<"\n";
    cout<<"Swaps: "<<cnt2<<"\n";
    cout<<"\n";

    cnt = cnt2 = 0;
}

int pivot(int a[], int n ,int l, int r){

    int i=l+1;
    int j= r;
    
    while(i<=j){

        while(i <= r && a[i]<=a[l]){ 
            i++;
            cnt1++;
        }
        while(j >= l && a[j]>a[l]){
            j--;
            cnt1++;
        }

        if(i<j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            cnt3++;
        }
    }

    int temp = a[l];
    a[l] = a[j];
    a[j] = temp;
    cnt3++;
    return j;
}

void QuickSort(int a[],int n, int l, int r){

    if(l>=r){
        return;
    }
    int pi = pivot(a,n,l,r);
    QuickSort(a,n,l,pi-1);
    QuickSort(a,n,pi+1, r);
}

void showQuickSort(int a[], int n, int l, int r){

    QuickSort(a,n,l,r);
    cout<<"Quick sort: ";
    // for(int p=0;p<n;p++) cout<<a[p]<<' ';
    // cout<<"\n";
    cout<<"Compares: "<<cnt1<<"\n";
    cout<<"\n";
    cout<<"Swaps: "<<cnt3<<"\n";
    cout<<"\n";

    cnt1 = 0;
    cnt3 = 0;
}


int main(){

    int a[10];
    int b[100];
    int c[1000];

    int i;

    int temp[20005];

    srand(time(0));
    for(i=0;i<10;i++){
        a[i]= rand();
    }

    cout<<"FOR 10 NUMBERS\n";

    for(i=0;i<10;i++){
        temp[i]= a[i];
    }

    BubbleSort(temp,10);

    for(i=0;i<10;i++){
        temp[i]= a[i];
    }

    InsertionSort(temp,10);

    for(i=0;i<10;i++){
        temp[i]= a[i];
    }

    SelectionSort(temp,10);

    for(i=0;i<10;i++){
        temp[i]= a[i];
    }

    showMergeSort(temp,10,0,9);

    for(i=0;i<10;i++){
        temp[i]= a[i];
    }

    showQuickSort(temp,10,0,9);

    srand(time(0));
    for(i=0;i<100;i++){
        b[i]= rand();
    }

    cout<<"FOR 100 NUMBERS\n";

    for(i=0;i<100;i++){
        temp[i]= b[i];
    }

    BubbleSort(temp,100);

    for(i=0;i<100;i++){
        temp[i]= b[i];
    }

    InsertionSort(temp,100);

    for(i=0;i<100;i++){
        temp[i]= b[i];
    }

    SelectionSort(temp,100);

    for(i=0;i<100;i++){
        temp[i]= b[i];
    }

    showMergeSort(temp,100,0,99);

    for(i=0;i<100;i++){
        temp[i]= b[i];
    }

    showQuickSort(temp,100,0,99);

    srand(time(0));
    for(i=0;i<1000;i++){
        c[i]= rand();
    }

    cout<<"FOR 1000 NUMBERS\n";

    for(i=0;i<1000;i++){
        temp[i]= c[i];
    }

    BubbleSort(temp,1000);

    for(i=0;i<1000;i++){
        temp[i]= c[i];
    }

    InsertionSort(temp,1000);

    for(i=0;i<1000;i++){
        temp[i]= c[i];
    }

    SelectionSort(temp,1000);

    for(i=0;i<1000;i++){
        temp[i]= c[i];
    }

    showMergeSort(temp,1000,0,999);

     for(i=0;i<1000;i++){
        temp[i]= c[i];
    }

    showQuickSort(temp,1000,0,999);

    return 0;
}