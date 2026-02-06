#include<bits/stdc++.h>
using namespace std;

struct minHeap{

    int a[200006]={0};
    int cnt =0;
    
    minHeap(){
        a[0]=-1; // keeping dummy element
    }

    void swim(int k){ //when child is smaller than parent node

        while(k>1 && a[k]<a[k/2]){
            swap(a[k],a[k/2]);
            k/=2;
        }
    }

    void sink(int k, int n){ //when parent is larger than child node
        
        if(n == 0) return;
        
        while(2*k<=n){
            int j = 2*k;
            if(a[j+1]< a[j] && j+1<=n) j++;
            if(a[j]>a[k]) break;
            swap(a[k],a[j]);
            k=j;
        }
    }


    void push(int x) {
        // Insert x into the heap
        cnt++;
        a[cnt]=x;
        swim(cnt);
    }

    void pop() {
        // Remove the top (maximum) element
        if(cnt==0){
            return;
        }
        swap(a[1],a[cnt]);
        cnt--;
        sink(1,cnt);
    }

    int peek() {
        // Return the top element or -1 if empty
        
        if(cnt==0) return -1;
        return a[1];
    }

    int size() {
        // Return the number of elements in the heap
        return cnt;
    }

    void bottomUp(){

        if(cnt ==0) return;
        for(int i=cnt/2;i>=1;i--) sink(i,cnt);
    }

    void displayheap(){
    
        for(int i =1; i<=cnt;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }

};

int main(){

    int n;
    cin>>n;
    minHeap t;
    t.cnt = n;
    for(int i=1;i<=n;i++) cin>>t.a[i];
    t.bottomUp();
    vector<int>res(n);
    for(int i=0;i<n;i++){
        res[i]= t.peek();
        t.pop();
    }
    for(int i=0;i<n;i++) cout<<res[i]<<" ";
    cout<<"\n";
    return 0;
}