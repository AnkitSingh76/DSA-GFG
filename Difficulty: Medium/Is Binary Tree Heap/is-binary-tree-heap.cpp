
class Solution {
public:

    int count(Node* root) {
        if (!root)
            return 0;

        return 1 + count(root->left) + count(root->right);
    }

    bool CBT(Node* root, int index, int total_nodes) {
        if (!root)
            return true;

        if (index >= total_nodes)
            return false;

        return CBT(root->left, 2 * index + 1, total_nodes) &&
               CBT(root->right, 2 * index + 2, total_nodes);
    }

    bool MaxHeap(Node* root) {
        if (!root)
            return true;

        if (root->left) {
            if (root->data < root->left->data)
                return false;

            if (!MaxHeap(root->left))
                return false;
        }

        if (root->right) {
            if (root->data < root->right->data)
                return false;

            if (!MaxHeap(root->right))
                return false;
        }

        return true;
    }

    bool isHeap(Node* root) {
        int num = count(root);

        if (!CBT(root, 0, num))
            return false;

        return MaxHeap(root);
    }
};
