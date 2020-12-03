ListNode* Solution::rotateRight(ListNode* A, int B) {
    ListNode *fp=A,*sp=A;
    int count = 0;
    while(count<B){
        fp = fp->next;
        if(fp==NULL)
            fp = A;
        count++;
    }
    if(fp==NULL || fp == sp)
        return A;
    while(fp && fp->next){
        fp=fp->next;
        sp=sp->next;
    }
    ListNode *head = sp->next;
    sp->next = NULL;
    fp->next = A;
    return head;
}
