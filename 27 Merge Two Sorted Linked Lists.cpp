Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{   

    if(first == NULL) return second;
    if(second == NULL) return first;
    // Write your code here.
    Node<int>* head = new Node<int>(-1);
    Node<int>* temp = head;
    while(first and second){    
        if(first->data < second->data){
            head->next = first;
            first = first->next;
        }else{
            head->next = second;
            second = second->next;
        }
        head = head->next;
    }

    if(first){
        head->next = first;
    }

    if(second){
        head->next = second;
    }

    return temp->next;

}