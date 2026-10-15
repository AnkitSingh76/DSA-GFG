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
  
    void lview(Node *root,int level, vector<int>&ans){
        if(root==NULL)
        return ;
        
        if(level==ans.size())
        ans.push_back(root->data);
        
        lview(root->left,level+1,ans);
        lview(root->right,level+1,ans);
    }
    vector<int> leftView(Node *root) {
        // code here
        vector<int>ans;
        if(root==NULL)
        return ans;
        
        lview(root,0,ans);
        return ans;
        // queue <Node *> q;
        //  vector<int>ans;
         
        //  if(root==NULL)
        //  return ans;
        // q.push(root);
       
        // while(!q.empty()){
        //     int n=q.size();
        //     ans.push_back(q.front()->data);
        //     while(n--){
        //         Node * temp=q.front();
        //         q.pop();
        //         if(temp->left)
        //         q.push(temp->left);
                
        //         if(temp->right)
        //         q.push(temp->right);
                
        //     }
        // }
        // return ans;
    }
};