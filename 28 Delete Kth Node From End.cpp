int Size(Node* head){
    Node* temp = head;
    int count = 0;
    while(temp){
        temp = temp->next;
        count++;
    }
    return count;
}

Node* removeKthNode(Node* &head, int K)
{
    int size = Size(head);
    if(size == K)
        return head->next;
    K = size-K-1;
    Node* tail = head;
    while(K--){
        tail = tail->next;
    }
    if(tail->next)
        tail->next = tail->next->next;
    else{
        tail->next = NULL;
    }
    return head;
}