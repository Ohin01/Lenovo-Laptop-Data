#include<bits/stdc++.h>
using namespace std;
int cnt =0;

struct node{

    int key;
    char val;
};

struct priorityQueue{

    node a[200006]={0};
    
    priorityQueue(){
        a[0].key = -1;
        a[0].val ='\0'; // keeping dummy element
    }

    void swim(int k){ //when child is larger than parent node

        while(k>1 && a[k].key>a[k/2].key){
            swap(a[k],a[k/2]);
            k/=2;
        }
    }

    void sink(int k, int n){ //when parent is smaller than child node
        
        if(n == 0) return;
        
        while(2*k<=n){
            int j = 2*k;
            if(a[j+1].key> a[j].key && j+1<=n) j++;
            if(a[j].key<a[k].key) break;
            swap(a[k],a[j]);
            k=j;
        }
    }


    void push(int x, char val) {
        // Insert x into the heap
        cnt++;
        a[cnt].key = x;
        a[cnt].val = val;
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
        return a[1].key;
    }

    char val_of_peek() {
        // Return the top element or -1 if empty
        
        if(cnt==0) return '\0';
        return a[1].val;
    }

    int size() {
        // Return the number of elements in the heap
        return cnt;
    }

    void displayheap(){
    
        for(int i =1; i<=cnt;i++){
            cout<<a[i].key<<" "<<a[i].val<<"\n";
        }
    }

};



int main(){

    priorityQueue temp;

    int choice;

    do{
        cout<<"1. push()\n";
        cout<<"2. pop()\n";
        cout<<"3. peek()\n";
        cout<<"4. val_of_peek()\n";
        cout<<"5. size()\n";
        cout<<"6. displayheap()\n";
        cout<<"7. exit\n";

        cout<<"Enter operations: ";
        cin>> choice;

        switch (choice)
        {
        case 1:
            cout<<"Enter key to push:\n";
            int x; cin>>x;
            cout<<"Enter value to push:\n";
            char y; cin>>y;

            temp.push(x,y);
            break;
        
        case 2:
            temp.pop();
            break;
        
        case 3:
            
            cout<<temp.peek()<<"\n";
            break;

        case 4:
            
            cout<<temp.val_of_peek()<<"\n";
            break;
        
        case 5:
            
            cout<<"size: "<<temp.size()<<"\n";
            break;
        
        case 6:
            
            cout<<"max heap: "<<"\n";
            temp.displayheap();
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