ListNode* Solution::removeNthFromEnd(ListNode* A, int B) {
    ListNode *fp=A,*sp=A;
    int count = 1;
    fp = fp->next;
    while(count<B && fp){
        fp = fp->next;
        count++;
    }
    if(fp==NULL){
        A = A->next;
        return A;
    }
    while(fp && fp->next){
        fp=fp->next;
        sp=sp->next;
    }
    
    sp->next = sp->next->next;
    return A;
}
