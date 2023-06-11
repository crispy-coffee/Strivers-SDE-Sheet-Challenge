Node *getListAfterReverseOperation(Node *head, int n, int b[], int index=0){
	// Write your code here.
	while(index<n and b[index]==0){
		index++;
	}

	if(!head or !head->next or index==n)
		return head;
	

	int k = b[index];

	Node* prev = NULL;
	Node* curr = head;
	Node* next = NULL;

	while(curr and k--){
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}


	head->next = getListAfterReverseOperation(next, n, b, index+1);

	return prev;
}