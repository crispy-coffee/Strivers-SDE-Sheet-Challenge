Node *firstNode(Node *head)
{
    //    Write your code here.
    Node* fast = head;
    Node* slow = head;
    bool cycle = false;
    while(fast and fast->next){
        fast = fast->next->next;
        slow = slow->next;

        if(slow == fast){
            cycle = true;
            break;
        }
    }

    if(cycle == false)
        return NULL;

    fast = head;
    while(slow != fast){
        fast = fast->next;
        slow = slow->next;
    }

    return slow;
}