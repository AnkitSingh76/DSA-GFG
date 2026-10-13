/* Node Structure
class Node {
public:
    int data;
    struct Node* left;
    struct Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    int getSize(Node* root) {
        // code here
        if(root==NULL)
        return 0;
        
        else
        return 1+getSize(root->left)+getSize(root->right);
    }
};