/*
Definition for Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  
  
    void rview(Node *root,int level, vector<int>&ans){
            if(root==NULL)
            return ;

            if(level==ans.size())
            ans.push_back(root->data);

            rview(root->right,level+1,ans);
            rview(root->left,level+1,ans);
        }


      
             
    vector<int> rightView(Node *root) {
        //  code here
        vector<int>ans;
            if(root==NULL)
            return ans;

            rview(root,0,ans);
            return ans;
        
    }
};