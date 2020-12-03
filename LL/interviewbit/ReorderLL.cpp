ListNode* Solution::reorderList(ListNode* head) {
    if(head == NULL)    return NULL;
    ListNode *slow = head, *fast = head; 
    while (fast && fast->next) { 
        slow = slow->next; 
        fast = fast->next->next; 
    } 

    // 2) Split the linked list in two halves
    ListNode* head1 = head, *head2 = slow->next; 
    slow->next = NULL; 
    // reverse 2nd half
    reverselist(&head2); 

    // 4) Merge alternate nodes 
    head = new ListNode(0); 
    ListNode* curr = head; 
    while (head1 || head2) { 
        if (head1) { 
            curr->next = head1; 
            curr = curr->next; 
            head1 = head1->next; 
        } 
        if (head2) { 
            curr->next = head2; 
            curr = curr->next; 
            head2 = head2->next; 
        } 
    } 
    return head->next;
}
