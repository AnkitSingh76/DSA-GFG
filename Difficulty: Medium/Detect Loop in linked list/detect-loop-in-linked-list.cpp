/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */



class Solution {
  public:
  
    bool detectLoop(Node* head) {
        // code here
     Node *fast=head, *slow=head;
     while(fast!=NULL && fast->next!=NULL){
         slow=slow->next;
         fast=fast->next->next;
         if(fast==slow)
         return 1;
     }
     return 0;
    }
};