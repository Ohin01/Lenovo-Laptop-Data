// C++ program to sort linked list
// using insertion sort
#include <bits/stdc++.h>
using namespace std;

class Node {
  	public:
    	int val;
    	struct Node* next;
    	Node(int x) {
        	val = x;
        	next = NULL;
    	}
};

// Function to insert a new_node in 
// the result list.
Node* sortedInsert(Node* newnode, Node* sorted) {
    
    // Special case for the head end
    if (sorted == NULL || 
        sorted->val >= newnode->val) {
        newnode->next = sorted;
        sorted = newnode;
    }
    else {
        Node* curr = sorted;
        
        // Locate the node before the point
      	// of insertion
        while (curr->next != NULL && 
               curr->next->val < newnode->val) {
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
    
    return sorted;
}

Node* insertionSort(Node* head) {
    
    // Initialize sorted linked list
    Node* sorted = NULL;
    Node* curr = head;
    
    // Traverse the given linked list and insert 
    // every node to sorted
    while (curr != NULL) {
        
        // Store next for next iteration
        Node* next = curr->next;
        
        // Insert current in sorted linked list
        sorted = sortedInsert(curr, sorted);
        
        // Update current
        curr = next;
    }
    
    return sorted;
}

void printList(Node* curr) {
    while (curr != NULL) {
        cout << " " << curr->val;
        curr = curr->next;
    }
}

int main() {
    
    // Create a hard-coded linked list:
    // 5->4->1->3->2
    Node* head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(2);

    head = insertionSort(head);

    printList(head);

    return 0;
}