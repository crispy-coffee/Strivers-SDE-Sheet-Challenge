Node *addTwoNumbers(Node *num1, Node *num2)
{
    Node* head = new Node();
    Node* sum = head;
    int carry = 0;

    while(num1 or num2 or carry){
        int a=0,b=0;
        if(num1){
            a = num1->data;
            num1 = num1->next;
        }

        if(num2){
            b = num2->data;
            num2 = num2->next;
        }


        int total = a+b+carry;
        int number = total%10;
        carry = total/10;

        sum->next = new Node(number);
        sum = sum->next;
    }

    return head->next;
}

