/* Node Structure
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = nullptr;
        right = nullptr;
    }
}
*/




class Solution {
  public:

    int pathsum(Node *root, int &sum) {
        if (root == nullptr)
            return 0;

        if (!root->left && !root->right)
            return root->data;

        int left = pathsum(root->left, sum);
        int right = pathsum(root->right, sum);

        if (root->left && root->right) {
            sum = max(sum, root->data + left + right);
            return root->data + max(left, right);
        }

        if (root->left)
            return root->data + left;

        return root->data + right;
    }

    int maxPathSum(Node *root) {
        if (root == nullptr)
            return -1;

        int sum = INT_MIN;
        pathsum(root, sum);

        if (sum == INT_MIN)
            return -1;

        return sum;
    }
};
