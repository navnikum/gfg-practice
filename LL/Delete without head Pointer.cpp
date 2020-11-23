void deleteNode(Node *node){
   Node *prev;
   if(node == NULL) return;
   while(node->next){
       node->data = node->next->data;
       prev = node;
       node = node->next;
   }
   // remove last element
   prev->next = NULL;
}
