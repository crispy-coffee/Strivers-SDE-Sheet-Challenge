LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    if(!head)
        return head;

    map<LinkedListNode<int>*,LinkedListNode<int>*> target;

    LinkedListNode<int>* tail = head;
    LinkedListNode<int>* new_head = new LinkedListNode<int>(head->data);
    LinkedListNode<int>* new_tail = new_head;
    target[tail] = new_tail;

    while(tail->next){
        new_tail->next = new LinkedListNode<int>(tail->next->data);
        new_tail = new_tail->next;
        tail = tail->next;
        target[tail] = new_tail;
    }

    tail = head;
    new_tail = new_head;

    while(tail){
        new_tail->random = target[tail->random];
        new_tail = new_tail->next;
        tail = tail->next;
    }

    return new_head;
}
