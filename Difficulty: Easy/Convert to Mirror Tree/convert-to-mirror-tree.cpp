/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
    void mirror(Node* root) {
        // code here
        if(root==NULL)
        return ;
        
        Node *temp=root->right;
        root->right=root->left;
        root->left=temp;
        
        mirror(root->left);
        mirror(root->right);
    }
};