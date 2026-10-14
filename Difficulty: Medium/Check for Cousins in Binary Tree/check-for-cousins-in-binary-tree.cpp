/* Structure of binary tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/
class Solution {
  public:
  
    bool parent(Node *root,int a ,int b){
        if(root==NULL )
        return 0;
        
        if(root->left && root->right){
            if(root->left->data==a && root->right->data==b)
            return 1;
            
            if(root->left->data==b && root->right->data==a)
            return 1;
        }
        
        return parent(root->left,a,b) || parent(root->right,a,b);
    }
    bool areCousins(Node* root, int a, int b) {
        // code here
        
        if(root == NULL || a == b)
            return false;
        queue<Node *>q;
        q.push(root);
        int l1=-1,l2=-1;
        int level=0;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                Node *temp=q.front();
                q.pop();
                if(temp->data==a)
                l1=level;
                
                if(temp->data==b)
                l2=level;
                
                if(temp->left)
                q.push(temp->left);
                
                if(temp->right)
                q.push(temp->right);
            }
           if(l1 != -1 || l2 != -1) {
               if(l1 == l2 && l1 != -1)
                   return !parent(root, a, b);

               return false;
           }
             level++;
        }
        return false;
         
    }
};