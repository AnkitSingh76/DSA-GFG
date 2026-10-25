/* Structure of a Binary Search Tree node
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
}; */

class Solution {
  public:
  
    void inorder(Node *root,vector<int>&ans){
        
        if(!root)
        return;
        
        inorder(root->left,ans);
        ans.push_back(root->data);
        inorder(root->right,ans);
        
    }
    vector<int> merge(Node *r1, Node *r2) {
        // code here
        vector<int>ans1;
        vector<int>ans2;
        
        inorder(r1,ans1);
        inorder(r2,ans2);
        
        vector<int>ans;
        int i=0,j=0;
        
        while(i<ans1.size() && j<ans2.size()){
            if(ans1[i]<ans2[j]){
            ans.push_back(ans1[i++]);
            }
            
            else
            ans.push_back(ans2[j++]);
        }
        
        while(i<ans1.size()){
        ans.push_back(ans1[i++]);
        }
        
        while(j<ans2.size()){
        ans.push_back(ans2[j++]);
        }
        
        return ans;
        
        
    }
};