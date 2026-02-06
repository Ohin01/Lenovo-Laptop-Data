#include <bits/stdc++.h>
using namespace std;


class Node {
public:
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return (node);
}


void bstTodll(Node* root, Node*& head)
{
    
    if (!root)
        return;

    
    bstTodll(root->right, head);

   
    root->right = head;

    
    if (head) {

       
        head->left = root;
    }

 
    head = root;

   
    bstTodll(root->left, head);
}


Node* mergeLinkedList(Node* head1, Node* head2)
{

    Node* head = NULL;
    Node* tail = NULL;

    while (head1 && head2) {

        if (head1->data < head2->data) {

            if (!head)
                head = head1;
            else {

                tail->right = head1;
                head1->left = tail;
            }

            tail = head1;
            head1 = head1->right;
        }

        else {

            if (!head)
                head = head2;
            else {
                tail->right = head2;
                head2->left = tail;
            }

            tail = head2;
            head2 = head2->right;
        }
    }

    while (head1) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    
    return head;
}


Node* sortedListToBST(Node*& head, int n)
{
    
    if (n <= 0 || !head)
        return NULL;

   
    Node* left = sortedListToBST(head, n / 2);

    Node* root = head;
    root->left = left;
    head = head->right;

    
    root->right = sortedListToBST(head, n - (n / 2) - 1);

    
    return root;
}


Node* mergeTrees(Node* root1, Node* root2, int m, int n)
{
   

    Node* head1 = NULL;
    bstTodll(root1, head1);
    head1->left = NULL;

    Node* head2 = NULL;
    bstTodll(root2, head2);
    head2->left = NULL;

   
    Node* head = mergeLinkedList(head1, head2);

   
    return sortedListToBST(head, m + n);
}

void printInorder(Node* node)
{
   
    if (!node) {
        return;
    }

    printInorder(node->left);

     
    cout << node->data << " ";

    printInorder(node->right);
}


int main()
{

    Node* root1 = newNode(100);
    root1->left = newNode(50);
    root1->right = newNode(300);
    root1->left->left = newNode(20);
    root1->left->right = newNode(70);


    Node* root2 = newNode(80);
    root2->left = newNode(40);
    root2->right = newNode(120);

    
    Node* mergedTree = mergeTrees(root1, root2, 5, 3);

    cout << "Following is Inorder traversal of the merged "
            "tree \n";
    printInorder(mergedTree);

    return 0;
}

