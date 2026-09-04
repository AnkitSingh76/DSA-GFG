/* Structure of Linked List Node
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
};*/

class Solution {
public:

    Node* merge(Node* a, Node* b) {

        Node* dummy = new Node(0);
        Node* tail = dummy;

        while (a != NULL && b != NULL) {

            if (a->data <= b->data) {
                tail->bottom = a;
                a = a->bottom;
            }
            else {
                tail->bottom = b;
                b = b->bottom;
            }

            tail = tail->bottom;
        }

        if (a != NULL)
            tail->bottom = a;
        else
            tail->bottom = b;

        return dummy->bottom;
    }


    Node* flatten(Node* head) {

        if (head == NULL)
            return NULL;

        // Store all vertical list heads
        vector<Node*> lists;

        Node* curr = head;

        while (curr != NULL) {
            lists.push_back(curr);

            Node* next = curr->next;
            curr->next = NULL;   // remove next pointer

            curr = next;
        }

        // Merge lists pair by pair
        while (lists.size() > 1) {

            vector<Node*> newLists;

            for (int i = 0; i < lists.size(); i += 2) {

                if (i + 1 < lists.size())
                    newLists.push_back(
                        merge(lists[i], lists[i + 1])
                    );
                else
                    newLists.push_back(lists[i]);
            }

            lists = newLists;
        }

        return lists[0];
    }
};