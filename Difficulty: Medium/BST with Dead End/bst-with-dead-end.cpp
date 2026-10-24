/* Tree Node structure
class Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = right = nullptr;
    }
};*/

class Solution {
  public:
  
  bool dead(Node *root,int lower,int upper){
      if(!root)
      return 0;
      
       if(!root->left && !root->right)
        {
            if(root->data - lower==1 &&  upper- root->data==1)
            return 1;
            else
            return 0;
        }
        return dead(root->left,lower,root->data) || dead(root->right,root->data,upper);
        
  }
    bool isDeadEnd(Node *root) {
        
        int upper=INT_MAX;
       return dead(root,0,upper);
        
        
    }
};