void deleteNode(LinkedListNode<int> * node) {
    // Write your code here.
    *node = *node->next;
}