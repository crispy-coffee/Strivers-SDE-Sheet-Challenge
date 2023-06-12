Node *rotate(Node *head, int k) {
     // Write your code here. 
     vector<int> store;
     Node* temp = head;

     while(temp){
          store.push_back(temp->data);
          temp = temp->next;
     }

     Node* face = new Node();
     Node* tail = face;
     int n = store.size();
     int start = n - (k%n);
     for(int i=0; i<n; i++){
          tail->next = new Node(store[(start+i)%n]);
          tail = tail->next;
     }

     return face->next;
}