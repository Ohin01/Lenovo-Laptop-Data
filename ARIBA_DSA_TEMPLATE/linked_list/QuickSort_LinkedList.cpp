#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* curr) {
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Returns the last node of the list
Node* getTail(Node* cur) {
    while (cur != nullptr && cur->next != nullptr)
        cur = cur->next;
    return cur;
}

// Partitions the list taking the first element as the pivot
Node* partition(Node* head, Node* tail) {
  
  	// Select the first node as the pivot node
    Node* pivot = head;
  
    // 'pre' and 'curr' are used to shift all 
  	// smaller nodes' data to the left side of the pivot node
    Node* pre = head;
    Node* curr = head;

    // Traverse the list until you reach the node after the tail
    while (curr != tail->next) {
        
        if (curr->data < pivot->data) {
			swap(curr->data, pre->next->data);
          
          	// Move 'pre' to the next node
            pre = pre->next;
        }
        
      	// Move 'curr' to the next node
        curr = curr->next;
    }
    
    swap(pivot->data, pre->data);
    
  	// Return 'pre' as the new pivot
    return pre;
}

// Helper function for quick sort
void quickSortHelper(Node* head, Node* tail) {
  
    // Base case: if the list is empty or consists of a single node
    if (head == nullptr || head == tail) {
        return;
    }
    
  	// Call partition to find the pivot node
    Node* pivot = partition(head, tail);
    
  	// Recursive call for the left part of the list (before the pivot)
    quickSortHelper(head, pivot);
    
  	// Recursive call for the right part of the list (after the pivot)
    quickSortHelper(pivot->next, tail);
}

// The main function for quick sort. This is a wrapper over quickSortHelper
Node* quickSort(Node* head) {
    
    Node* tail = getTail(head);
    
  	// Call the helper function to sort the list
    quickSortHelper(head, tail);
    return head;
}

int main() {
  
    // Creating a linked list: 30 -> 3 -> 4 -> 20 -> 5
    Node* head = new Node(30);
    head->next = new Node(3);
    head->next->next = new Node(4);
    head->next->next->next = new Node(20);
    head->next->next->next->next = new Node(5);

    head = quickSort(head);
    printList(head);

    return 0;
}