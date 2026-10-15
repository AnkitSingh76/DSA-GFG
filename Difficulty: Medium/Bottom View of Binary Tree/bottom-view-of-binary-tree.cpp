/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/


class Solution {
  public:

    void find(Node *root, int pos, int &l, int &r) {
        if (!root)
            return;

        l = min(pos, l);
        r = max(pos, r);

        find(root->left, pos - 1, l, r);
        find(root->right, pos + 1, l, r);
    }

    void Bview(Node *root, int pos, vector<int>& ans,
               vector<int>& level, int lev, int l) {
        if (!root)
            return;

        int index = pos - l;

        // Update for the bottommost node
        if (lev >= level[index]) {
            ans[index] = root->data;
            level[index] = lev;
        }

        Bview(root->left, pos - 1, ans, level, lev + 1, l);
        Bview(root->right, pos + 1, ans, level, lev + 1, l);
    }

    vector<int> bottomView(Node *root) {
        if (!root)
            return {};

        int l = 0, r = 0;
        find(root, 0, l, r);

        vector<int> ans(r - l + 1);
        vector<int> level(r - l + 1, -1);

        Bview(root, 0, ans, level, 0, l);

        return ans;
    }
};
