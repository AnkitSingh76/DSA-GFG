/* Structure of Linked List Node
class Node {
	public:
	int data;
	Node* next;
	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};
*/
class Solution {
	public:
	Node* deleteNode(Node* head, int x) {
		// code here
		if (x == 1) {
			Node *temp = head;
			head = head->next;
			delete temp;
			
			return head;
		}
		else {
			Node *curr = head;
			Node *prev = NULL;
			x--;
			while (x--) {
				prev = curr;
				curr = curr->next;
				
			}
			prev->next = curr->next;
			delete curr;
			
			return head;
		}
	}
};
