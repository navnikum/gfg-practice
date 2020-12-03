ListNode* Solution::addTwoNumbers(ListNode* A, ListNode* B) {
    ListNode *res = new ListNode(0), *head = res;
    if(!A)  return B;   if(!B)  return A;
    int sum , carry = 0;
    while(A || B || carry){
        sum = carry + (A?A->val:0) + (B?B->val:0);
        carry = sum/10;
        res->next = new ListNode(sum%10);  
        res = res->next;
        A = A->next;
        B = B->next;
    }
    return head->next;
}
