ListNode* IntersectionNode(ListNode* head1, ListNode* head2) {
    int l1 = LLsize(head1), l2 = LLsize(head2), k;
    ListNode *curr1, *curr2;
    if(l2 > l1)
        curr1 = head2, curr2 = head1, k = (l2-l1);
    else    
        curr1 = head1, curr2 = head2, k = (l1-l2);
        
    int cnt=0;
    while(cnt<k)    curr1 = curr1->next, cnt++;
    while(curr1 && curr2){
        if(curr1 == curr2)
            return curr1;
        curr1 = curr1->next;
        curr2 = curr2->next;
    }
    return NULL;
}

// M2
ListNode* Solution::getIntersectionNode(ListNode* head1, ListNode* head2) {
    ListNode *curr1 = head1, *curr2 = head2;
    if(!curr1 || !curr2)  return NULL;
    while(curr1 != curr2){
        curr1 = (curr1) ? curr1->next : head2;
        curr2 = (curr2) ? curr2->next : head1; 
    }
    return curr1;
}
