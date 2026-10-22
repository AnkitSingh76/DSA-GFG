/* Structure of a Tree Node
class Node {
    int data;
    Node* right;
    Node* left;
    Node(int x){
        data = x;
        right = nullptr;
        left = nullptr;
    }
}; */

class Solution {
  public:
  
    void ksum(Node *root,int &sum,int &k){
        if(!root)
        return;
        
        ksum(root->left,sum,k);
        k--;
        if(k>=0)
        sum+=root->data;
        
        if(k<=0)
        return;
        
        ksum(root->right,sum,k);
        
    }
    int sum(Node* root, int k) {
        // code here
        int sum=0;
        ksum(root,sum,k);
        return sum;
        
    }
};