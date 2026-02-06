#include<bits/stdc++.h>
using namespace std;

struct maxHeap{

    int a[200006]={0};
    int cnt =0;
    maxHeap(){
        a[0]=-1; // keeping dummy element
    }

    void swim(int k){ //when child is larger than parent node

        while(k>1 && a[k]>a[k/2]){
            swap(a[k],a[k/2]);
            k/=2;
        }
    }

    void sink(int k, int n){ //when parent is smaller than child node
        
        if(n == 0) return;
        
        while(2*k<=n){
            int j = 2*k;
            if(j+1<=n && a[j+1]> a[j]) j++;
            if(a[j]<a[k]) break;
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

    void displayheap(){
    
        for(int i =1; i<=cnt;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }

    void bottomUp(){

        if(cnt ==0) return;
        for(int i=cnt/2;i>=1;i--) sink(i,cnt);
    }

    void deleteItem(int i){
        if(i<1 && i>cnt) return;

        else if(cnt ==0){
            return;
        }

        swap(a[i],a[cnt]);
        cnt--;

        if(i>1 && a[i]>a[i/2]){
            swim(i);
            return;
        }
        sink(i,cnt);
    }

};



int main(){

    maxHeap temp;

    int choice;

    do{
        cout<<"1. push()\n";
        cout<<"2. pop()\n";
        cout<<"3. peek()\n";
        cout<<"4. size()\n";
        cout<<"5. displayheap()\n";
        cout<<"6. deleteItem()\n";
        cout<<"7. exit\n";

        cout<<"Enter operations: ";
        cin>> choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter number to push:\n";
            int x; cin>>x;
            temp.push(x);
            break;
        
        case 2:
            temp.pop();
            break;
        
        case 3:
            
            cout<<temp.peek()<<"\n";
            break;
        
        case 4:
            
            cout<<"size: "<<temp.size()<<"\n";
            break;
        
        case 5:
            
            cout<<"max heap: "<<"\n";
            temp.displayheap();
            break;

        case 6:

            cout<<"Enter index:";
            int i; cin>>i;
            temp.deleteItem(i);
            break;

        case 7:

            cout<<"Exiting\n";
            break;

        default:
            cout<<"Invalid choice!\n";
            break;
        }
    }while(choice!=7);
   


    return 0;
}