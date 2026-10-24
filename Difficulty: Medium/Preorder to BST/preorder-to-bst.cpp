/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:

    Node* BST(vector<int>& pre, int& index, int lower, int upper) {
        if (index == pre.size() ||pre[index]<lower || pre[index]>upper)
            return NULL;

   

        Node* root = new Node(pre[index++]);
    

        root->left = BST(pre, index, lower, root->data);
        root->right = BST(pre, index, root->data, upper);

        return root;
    }

    Node* preToBST(vector<int>& pre) {
        int index = 0;
        return BST(pre, index, INT_MIN, INT_MAX);
    }
};