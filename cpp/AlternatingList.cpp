#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Function to print a linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to append a node to the linked list
void appendNode(ListNode*& head, int value) {
    if (!head) {
        head = new ListNode(value);
        return;
    }
    ListNode* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new ListNode(value);
}

// Function to split a linked list into two alternating lists
void alternatingSplit(LinkedList& front, ListNode*& newList) {

    
   
    if (!head || !head->next) return;

    newList = head->next;
    ListNode* curr1 = head;
    ListNode* curr2 = newList;

    while (curr1 && curr1->next && curr2 && curr2->next) {

        curr1->next = curr2->next;
        curr2->next = curr2->next->next;
        curr1 = curr1->next;
        curr2 = curr2->next;

    }

    curr1->next = nullptr;
    curr2->next = nullptr;

}

void splitList (ListNode& front, )

// Main function to test the implementation
int main() {
    ListNode* head = nullptr;

    // Creating the linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    appendNode(head, 1);
    appendNode(head, 2);
    appendNode(head, 3);
    appendNode(head, 4);
    appendNode(head, 5);
    appendNode(head, 6);

    cout << "Original List:\n";
    printList(head);

    ListNode* newList = nullptr;

    // Calling the function to split the linked list
    alternatingSplit(head, newList);

    cout << "Modified First List:\n";
    printList(head);

    cout << "Second List (Extracted Even Nodes):\n";
    printList(newList);

    return 0;
}
