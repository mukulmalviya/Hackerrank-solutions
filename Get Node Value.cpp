// hackerrank problem Get Node Value (given index from the end)


int getNode(SinglyLinkedListNode* head, int positionFromTail) {
    static int count = -1;
    static int value = -1;
    //static int ans = -1;
    if(head->next == nullptr)
    {
        count = 0;
        return head->data;
    }
    value = getNode(head->next,positionFromTail); //gets and retains node value of last node till we find our desired node.
    count++;
    if(count == positionFromTail)
    {
        return value = head->data;
    }
    return value;
}
