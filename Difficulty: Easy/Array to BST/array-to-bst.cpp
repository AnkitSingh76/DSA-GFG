/*
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
};
*/

class Solution {
  public:

    Node* arraytobst(vector<int>& arr, int start, int end) {
        if (start > end)
            return nullptr;

        int mid = start + (end - start) / 2;

        Node* root = new Node(arr[mid]);

        root->left = arraytobst(arr, start, mid - 1);
        root->right = arraytobst(arr, mid + 1, end);

        return root;
    }

    Node* sortedArrayToBST(vector<int>& arr) {
        return arraytobst(arr, 0, arr.size() - 1);
    }
};