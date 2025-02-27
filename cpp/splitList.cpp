void alternatingSplit(LinkedList& front, ListNode*& newList) {

    ListNode* head = front.head;
   
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