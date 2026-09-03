/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:

    Node* Reverse(Node* curr, Node* prev) {
        if (curr == NULL)
            return prev;

        Node* front = curr->next;
        curr->next = prev;

        return Reverse(front, curr);
    }

    Node* addTwoLists(Node* head1, Node* head2) {

        // Remove leading zeros from first list
        while (head1 && head1->data == 0 && head1->next)
            head1 = head1->next;

        // Remove leading zeros from second list
        while (head2 && head2->data == 0 && head2->next)
            head2 = head2->next;

        // Reverse both lists
        Node* first = Reverse(head1, NULL);
        Node* second = Reverse(head2, NULL);

        Node* curr1 = first;
        Node* curr2 = second;

        Node* dummy = new Node(0);
        Node* tail = dummy;

        int carry = 0;

        // Add both lists
        while (curr1 || curr2 || carry) {

            int sum = carry;

            if (curr1) {
                sum += curr1->data;
                curr1 = curr1->next;
            }

            if (curr2) {
                sum += curr2->data;
                curr2 = curr2->next;
            }

            tail->next = new Node(sum % 10);
            tail = tail->next;

            carry = sum / 10;
        }

        // Reverse answer
        Node* ans = Reverse(dummy->next, NULL);

        // Remove leading zeros from answer
        while (ans && ans->data == 0 && ans->next)
            ans = ans->next;

        return ans;
    }
};