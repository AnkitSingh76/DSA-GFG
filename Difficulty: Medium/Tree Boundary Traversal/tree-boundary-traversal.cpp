/* Node Structure
class Node {
  public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:

    // Add left boundary, excluding leaf nodes
    void leftsub(Node *root, vector<int>& ans) {
        if (!root || (!root->left && !root->right))
            return;

        ans.push_back(root->data);

        if (root->left)
            leftsub(root->left, ans);
        else
            leftsub(root->right, ans);
    }

    // Add all leaf nodes from left to right
    void leaf(Node *root, vector<int>& ans) {
        if (!root)
            return;

        if (!root->left && !root->right) {
            ans.push_back(root->data);
            return;
        }

        leaf(root->left, ans);
        leaf(root->right, ans);
    }

    // Add right boundary in bottom-up order
    void rightsub(Node *root, vector<int>& ans) {
        if (!root || (!root->left && !root->right))
            return;

        if (root->right)
            rightsub(root->right, ans);
        else
            rightsub(root->left, ans);

        ans.push_back(root->data);
    }

    vector<int> boundaryTraversal(Node *root) {
        vector<int> ans;

        if (!root)
            return ans;

        ans.push_back(root->data);

        // Root is already included
        if (!root->left && !root->right)
            return ans;

        leftsub(root->left, ans);
        leaf(root, ans);
        rightsub(root->right, ans);

        return ans;
    }
};