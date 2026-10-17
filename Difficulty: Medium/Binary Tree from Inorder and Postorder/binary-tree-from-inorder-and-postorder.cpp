
/* Structure of binary tree node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:

    int find(vector<int>& inorder, int target, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (inorder[i] == target)
                return i;
        }
        return -1;
    }

    Node* tree(vector<int>& inorder, vector<int>& postorder,
               int inStart, int inEnd, int& index) {

        if (inStart > inEnd)
            return nullptr;

        // Last unprocessed postorder element is the root
        Node* root = new Node(postorder[index]);
        index--;

        // Find root position in inorder
        int pos = find(inorder, root->data, inStart, inEnd);

        // Build right subtree first
        root->right = tree(inorder, postorder,
                           pos + 1, inEnd, index);

        // Build left subtree
        root->left = tree(inorder, postorder,
                          inStart, pos - 1, index);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int index = (int)postorder.size() - 1;

        return tree(inorder, postorder, 0,
                    (int)inorder.size() - 1, index);
    }
};
