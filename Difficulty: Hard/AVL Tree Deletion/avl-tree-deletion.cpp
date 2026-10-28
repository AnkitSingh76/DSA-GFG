
/* Structure of AVL Tree Node
class Node {
  public:
    int data, height;
    Node *left, *right;

    Node(int x) {
        data = x;
        height = 1;
        left = right = nullptr;
    }
}; */

class Solution {

    int getheight(Node *root) {
        if (!root)
            return 0;

        return root->height;
    }

    int getbalance(Node *root) {
        if (!root)
            return 0;

        return getheight(root->left) - getheight(root->right);
    }

    Node *rightrotation(Node *root) {
        Node *child = root->left;
        Node *childright = child->right;

        child->right = root;
        root->left = childright;

        root->height = 1 + max(getheight(root->left),
                               getheight(root->right));

        child->height = 1 + max(getheight(child->left),
                                getheight(child->right));

        return child;
    }

    Node *leftrotation(Node *root) {
        Node *child = root->right;
        Node *childleft = child->left;

        child->left = root;
        root->right = childleft;

        root->height = 1 + max(getheight(root->left),
                               getheight(root->right));

        child->height = 1 + max(getheight(child->left),
                                getheight(child->right));

        return child;
    }

public:
    Node* deleteNode(Node* root, int data) {

        if (!root)
            return nullptr;

        // Step 1: Perform normal BST deletion
        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        }
        else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        }
        else {

            // Case 1: No child
            if (!root->left && !root->right) {
                delete root;
                return nullptr;
            }

            // Case 2: Only left child
            else if (root->left && !root->right) {
                Node *temp = root->left;
                delete root;
                return temp;
            }

            // Case 3: Only right child
            else if (!root->left && root->right) {
                Node *temp = root->right;
                delete root;
                return temp;
            }

            // Case 4: Two children
            else {
                Node *curr = root->right;

                // Find inorder successor
                while (curr->left) {
                    curr = curr->left;
                }

                root->data = curr->data;

                root->right = deleteNode(root->right,
                                         curr->data);
            }
        }

        // Step 2: Update height
        root->height = 1 + max(getheight(root->left),
                               getheight(root->right));

        // Step 3: Calculate balance factor
        int balance = getbalance(root);

        // Step 4: LL case
        if (balance > 1 &&
            getbalance(root->left) >= 0) {
            return rightrotation(root);
        }

        // Step 5: LR case
        if (balance > 1 &&
            getbalance(root->left) < 0) {
            root->left = leftrotation(root->left);
            return rightrotation(root);
        }

        // Step 6: RR case
        if (balance < -1 &&
            getbalance(root->right) <= 0) {
            return leftrotation(root);
        }

        // Step 7: RL case
        if (balance < -1 &&
            getbalance(root->right) > 0) {
            root->right = rightrotation(root->right);
            return leftrotation(root);
        }

        return root;
    }
};
