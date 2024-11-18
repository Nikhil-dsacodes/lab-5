
/* ADT on Doubly Linked List */

#include<iostream>
#include<cstring>
#include<stdlib.h>
using namespace std;

// Self-referential structure
struct Node {
public:
    int val;
    Node* next;
    Node* prev;
};

// Function to print the linked list
void printList(Node* head) {
    cout<<"NULL <-> ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->val << " <-> ";
        current = current->next;
    }
    cout << "NULL " << endl <<endl;
}

// Function to insert a node after a specified value
void insertAfter(Node* &head, int targetVal, int newVal) {
    Node* current = head;

    while (current != nullptr && current->val != targetVal) {
        current = current->next;
    }
    
    if (current != nullptr) {
        Node* newNode = new Node();
        newNode->val = newVal;

        // Inserting at the end of the list
        if (current->next == nullptr) {
            newNode->next = nullptr;
            newNode->prev = current;
            current->next = newNode;
        } else {
            // Inserting in between nodes
            newNode->next = current->next;
            newNode->prev = current;
            current->next->prev = newNode;
            current->next = newNode;
        }
    } 
}

// Function to insert a node before a specified value
void insertBefore(Node*& head, int targetVal, int newVal) {
    // Case when inserting before the head
    if (head->val == targetVal) {
        Node* newNode = new Node();
        newNode->val = newVal;
        newNode->next = head;
        newNode->prev = nullptr;
        head->prev = newNode;
        head = newNode;
    }
    // General case 
    Node* current = head;
    while(current->next->val != targetVal){
        current = current->next;
    }
    Node* newNode = new Node();
    newNode->val = newVal;
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

// Function to delete a node 
void deleteNode(Node*& head, int targetVal) {
// Head Node Case
if (head->val == targetVal) {
    Node* temp = head;
    head = head->next;
    head->prev = nullptr;
    delete temp; 
    return;
}
 
Node* current = head;

// Find the target node
while (current->val != targetVal) {
    current = current->next;
}

// Last Node Case
if (current->next == nullptr) {
    current->prev->next = nullptr;  
    delete current;
    return; 
}

// General Case 
Node* temp = current; 
current->prev->next = current->next;
current->next->prev = current->prev;
delete temp;
}

// Function to update a node
void updateNode(Node* & head, int numUpdate, int newVal) {
    Node* current = head;
    while(current->val != numUpdate){
        current = current->next;
    }
    current->val = newVal;
}


int main() {
    // Declaring nodes
    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();
    
    // Assigning Values to the node and Linking them
    node1->val = 10;
    node1->next = node2;
    node1->prev = nullptr;
    
    node2->val = 20;
    node2->next = node3;
    node2->prev = node1;
    
    node3->val = 30;
    node3->next = node4;
    node3->prev = node2;
    
    node4->val = 40;
    node4->next = nullptr;
    node4->prev = node3;
    
    // Printing the linked list
    printList(node1);

char op[10];
cout<<"Enter the operation you want to perform: ";
cin>>op;

if(strcmp(op, "insertion") == 0) {
    char a_or_b;
    int targetVal, newVal;

    cout << "\n(a/b): ";
    cin >> a_or_b;

    if (a_or_b == 'a') {
        cout << "After which number: ";
        cin >> targetVal;
        cout << "Insert value: ";
        cin >> newVal;
        insertAfter(node1, targetVal, newVal);
    } else if (a_or_b == 'b') {
        cout << "Before which number: ";
        cin >> targetVal;
        cout << "Insert value: ";
        cin >> newVal;
        insertBefore(node1, targetVal, newVal);
    } else {
        cout << "Invalid option." << endl;
    }

    // Printing the new list after insertion operation
    printList(node1);

    // Cleanup: delete nodes to avoid memory leaks
    Node* current = node1;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

if(strcmp(op, "deletion") == 0) {
    int delNum;
    cout<<"Enter the number you want to delete: ";
    cin>>delNum;
    deleteNode(node1, delNum);
    printList(node1);
}

if(strcmp(op, "update") == 0) {
    int numUpdate, newVal;
    cout<<"Enter the Number you want to Update: ";
    cin>>numUpdate;
    cout<<"Enter the New Value of the Number: ";
    cin>>newVal;
    updateNode(node1, numUpdate, newVal);
    printList(node1);
}
    

    return 0;
}

