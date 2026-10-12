/* Structure of Binary Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  
    void In(Node *root, vector<int>&ans){
        if(root==NULL)
        return;
        
        In(root->left,ans);
        ans.push_back(root->data);
        In(root->right,ans);
    }
    vector<int> inOrder(Node* root) {
        // code here
        vector<int>ans;
        In(root,ans);
        return ans;
    }
};