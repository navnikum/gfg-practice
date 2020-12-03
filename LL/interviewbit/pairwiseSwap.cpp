ListNode* Solution::swapPairs(ListNode* head) {
    if (head == NULL || head->next == NULL) 
        return head; 
    ListNode* curr = head->next->next;
    head->next->next = head;
    ListNode* newhead = head->next;
    head->next = swapPairs(curr);
    return newhead;
}
