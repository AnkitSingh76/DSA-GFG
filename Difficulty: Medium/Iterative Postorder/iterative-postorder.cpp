/* Binary Tree Node Structure
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
};
*/

class Solution {
  public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node *>s;
        s.push(node);
        vector<int>ans;
        
        while(!s.empty()){
            Node *temp=s.top();
            s.pop();
            
            ans.push_back(temp->data); 
            
            if(temp->left)
            s.push(temp->left);
            
            if(temp->right)
            s.push(temp->right);
            
            
          
        }
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};