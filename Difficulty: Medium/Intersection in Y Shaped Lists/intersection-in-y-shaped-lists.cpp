/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  code here
        Node *curr1=head1, *curr2=head2;
        int count1=0,count2=0;
        while(curr1!=NULL){
            count1++;
            curr1=curr1->next;
        }
        while(curr2!=NULL){
            count2++;
            curr2=curr2->next;
        }
        curr1=head1,curr2=head2;
        while(count1>count2){
            count1--;
            curr1=curr1->next;
            
        }
        while(count2>count1){
            count2--;
            curr2=curr2->next;
            
        }
        while(curr1!=curr2){
            curr1=curr1->next;
            curr2=curr2->next;
        }
      
        return curr1;
    }
};