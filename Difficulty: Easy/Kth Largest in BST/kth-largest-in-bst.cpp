/* Structure of a Binary Tree Node
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
  
    void klargest(Node *root,int &ans ,int &k){
        if(!root)
        return;
        
        klargest(root->right,ans,k);
        k--;
        
        if(k==0)
        ans=root->data;
        
        if(k<=0)
        return;
        
        klargest(root->left,ans,k);
    }
    int kthLargest(Node *root, int k) {
        // code here
        int ans=0;
        klargest(root,ans,k);
        return ans;
        
    }
};