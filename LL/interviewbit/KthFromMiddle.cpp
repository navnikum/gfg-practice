int Solution::solve(ListNode* A, int B) {
    int move = 0;
    ListNode* slow = NULL;
    ListNode* fast = A;
    while(fast && fast->next) {
        move++;
        if(move==B)    slow = A; // stop slow till Bth move
        else if(move>B) slow = slow->next;
        fast = fast->next->next;
    }
    return slow? slow->val : -1;
}
