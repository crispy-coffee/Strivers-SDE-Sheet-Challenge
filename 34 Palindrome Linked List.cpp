bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    vector<int> result;
    while(head){
        result.push_back(head->data);
        head = head->next;
    }


    int i=0, j=result.size()-1;
    while(i<j){
        if(result[i] != result[j])
            return false;
        i++,j--;
    }

    return true;
}