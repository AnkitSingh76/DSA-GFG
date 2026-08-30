/* Structure of Doubly Linked List Node
class Node {
  public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = nullptr;
    }
};
*/

class Solution {
  public:
    Node* insertAtPos(Node* head, int p, int x) {

        Node* curr = head;

        // Move curr to the p-th node
        while (p--) {
            curr = curr->next;
        }

        Node* temp = new Node(x);

        // Connect new node
        temp->next = curr->next;
        temp->prev = curr;

        // If not inserting at the end
        if (curr->next != NULL) {
            curr->next->prev = temp;
        }

        curr->next = temp;

        return head;
    }
};