/* Structure of a Binary Search Tree node
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class box {
public:
    bool bst;
    int size;
    int max, min;

    box(int data) {
        bst = 1;
        size = 1;
        max = data;
        min = data;
    }
};

class Solution {
public:

    box* find(Node* root, int& totalsize) {

        if (root == nullptr)
            return nullptr;

        // Case 1: Leaf node
        if (!root->left && !root->right) {
            totalsize = ::max(totalsize, 1);
            return new box(root->data);
        }

        // Case 2: Only right child
        else if (!root->left && root->right) {

            box* head = find(root->right, totalsize);

            if (head->bst && head->min > root->data) {
                head->size++;
                head->min = root->data;

                totalsize = ::max(totalsize, head->size);
                return head;
            }
            else {
                head->bst = 0;
                return head;
            }
        }

        // Case 3: Only left child
        else if (root->left && !root->right) {

            box* head = find(root->left, totalsize);

            if (head->bst && head->max < root->data) {
                head->size++;
                head->max = root->data;

                totalsize = ::max(totalsize, head->size);
                return head;
            }
            else {
                head->bst = 0;
                return head;
            }
        }

        // Case 4: Both children exist
        else {

            box* lefthead = find(root->left, totalsize);
            box* righthead = find(root->right, totalsize);

            if (lefthead->bst && righthead->bst &&
                lefthead->max < root->data &&
                righthead->min > root->data) {

                box* head = new box(root->data);

                head->size += lefthead->size + righthead->size;
                head->min = lefthead->min;
                head->max = righthead->max;

                totalsize = ::max(totalsize, head->size);

                return head;
            }
            else {
                lefthead->bst = 0;
                return lefthead;
            }
        }
    }

    int largestBst(Node* root) {
        int totalsize = 0;
        find(root, totalsize);
        return totalsize;
    }
};