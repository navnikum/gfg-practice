ListNode* Solution::detectCycle(ListNode* A) {
    ListNode *slow, *fast;
    slow = fast = A;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next;
        if(slow == fast)        break;
    }
    fast = A;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}
