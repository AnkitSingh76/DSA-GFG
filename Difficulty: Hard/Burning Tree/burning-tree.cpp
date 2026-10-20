/* Structure of binary tree Node
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
  
    int burn(Node *root,int &timer,int target){
        if(!root)
        return 0;
        
        if(root->data==target)
        return -1;
        
        int left=burn(root->left,timer,target);
        int right=burn(root->right,timer,target);
        
        if(left<0){
        timer=max(timer,abs(left)+right);
        return left-1;
        }
        if(right<0){
            timer=max(timer,left+abs(right));
            return right-1;
        }
        
        return 1+max(left,right);
        
    }
    
    void find(Node *root,int target,Node *&burnNode){
        if(!root)
        return;
        
        if(root->data==target){
            burnNode=root;
            return;
        }
            
            find(root->left,target,burnNode);
            find(root->right,target,burnNode);
       
    }
    
    int height(Node *root){
        if(!root)
        return 0;
        
        return 1+max(height(root->left),height(root->right));
    }
    int minTime(Node* root, int target) {
        // code here
        int timer=0;
        burn(root,timer,target);
        
        Node *burnNode=NULL;
        find(root,target,burnNode);
        
        int high=height(burnNode)-1;
        return max(timer,high);
    }
};