
/* Structure of a Tree Node
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
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

    Node* tree(vector<int>& inorder, vector<int>& preorder,
               int inStart, int inEnd, int& index) {

        if (inStart > inEnd)
            return nullptr;

        // First element in preorder is the root
        Node* root = new Node(preorder[index]);
        index++;

        // Find root position in inorder
        int pos = find(inorder, root->data, inStart, inEnd);

        // Construct left and right subtrees
        root->left = tree(inorder, preorder, inStart, pos - 1, index);
        root->right = tree(inorder, preorder, pos + 1, inEnd, index);

        return root;
    }

    Node* buildTree(vector<int>& inorder, vector<int>& preorder) {
        int index = 0;

        return tree(inorder, preorder, 0,
                    (int)inorder.size() - 1, index);
    }
};
