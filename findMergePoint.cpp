int findMergeNode(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* originalh1 = head1;
    SinglyLinkedListNode* originalh2 = head2;
    if(head1 == head2)
        return head1->data;
    
    while(head1->next != nullptr)
    {
        while(head2->next != nullptr)
        {
        if(head1->next == head2->next)
            return head1->next->data;
        head2 = head2->next;
        }
        head2 = originalh2;
        head1 = head1->next;
    }
        return head1->data;

}
