
Node *findMiddle(Node *head) {
    // Write your code here
    Node* turtle = head;
    Node* rabbit = head;
    while(rabbit and rabbit->next){
        rabbit = rabbit->next->next;
        turtle = turtle->next;
    }
    return turtle;

}

