/* Structure of tree node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
}; */

class Solution {
  public:

    Node* BST(vector<int>& post, int& index, int lower, int upper) {
        if (index < 0)
            return nullptr;

        int val = post[index];

        if (val < lower || val > upper)
            return nullptr;

        Node* root = new Node(val);
        index--;

        root->right = BST(post, index, root->data, upper);
        root->left = BST(post, index, lower, root->data);

        return root;
    }

    Node* constructTree(vector<int>& post) {
        int index = post.size() - 1;

        return BST(post, index, INT_MIN, INT_MAX);
    }
};