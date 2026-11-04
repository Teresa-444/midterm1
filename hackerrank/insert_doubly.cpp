DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* llist, int data) {
    DoublyLinkedListNode* new_node = new DoublyLinkedListNode(data);

    if(llist==nullptr || data<=llist->data) {
        new_node->next=llist;

        if(llist!=nullptr) {
            llist->prev=new_node;
        }

        return new_node;
    }

    DoublyLinkedListNode* current=llist;

    while(current->next!=nullptr && current->next->data<data) {
        current=current->next;
    }

    new_node->next=current->next;
    new_node->prev=current;

    if(current->next!=nullptr) {
        current->next->prev=new_node;
    }

    current->next=new_node;

    return llist;
}