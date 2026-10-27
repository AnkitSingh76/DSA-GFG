/* Structure of AVL Tree Node
class Node {
	public:
	int data;
	int height;
	Node *left, *right;
	Node(int x) {
		data = x;
		height = 1;
		left = right = nullptr;
	}
}; */

class Solution {
	public:
	int getheight(Node *root) {
		if (!root)
			return 0;
		
		return root->height;
	}
		int getbalance(Node *root) {
			return getheight(root->left) - getheight(root->right);
		}
		
		Node *rightrotation(Node *root) {
			Node *child = root->left;
			Node * childright = child->right;
			
			child->right = root;
			root->left = childright;
			
			root->height = 1 + max(getheight(root->left), getheight(root->right));
			child->height = 1 + max(getheight(child->left), getheight(child->right));
			
			return child;
		}
		
		Node *leftrotation(Node *root) {
			Node *child = root->right;
			Node *childleft = child->left;
			
			child->left = root;
			root->right = childleft;
			
			root->height = 1 + max(getheight(root->left), getheight(root->right));
			child->height = 1 + max(getheight(child->left), getheight(child->right));
			
			return child;
		}
		
		Node* insertToAVL(Node* root, int key) {
			// code here
			if (!root)
				return new Node(key);
			
			if (key < root->data)
				root->left = insertToAVL(root->left, key);
			
			else if (key > root->data)
				root->right = insertToAVL(root->right, key);
			
			else
				return root;
			
			root->height = 1 + max(getheight(root->left), getheight(root->right));
			
			int balance = getbalance(root);
			
			if (balance>1 && key < root->left->data)
				{
				return rightrotation(root);
			}
			
			else if (balance<-1 && key > root->right->data)
				{
				return leftrotation(root);
			}
			
			else if (balance>1 && key > root->left->data)
				{
				root->left= leftrotation(root->left);
				return rightrotation(root);
			}
			
			else if (balance<-1 && key < root->right->data)
				{
				root->right=rightrotation(root->right);
				return leftrotation(root);
			}
			else
				{
				return root;
			}
			
		}
	};
