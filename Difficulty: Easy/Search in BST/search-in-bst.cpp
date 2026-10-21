/* Definition for Node
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    bool search(Node* root, int key) {
        // code here
        if(!root)
        return 0;
        
        if(root->data==key)
        return 1;
        
        else if(root->data > key)
        return search(root->left,key);
        
        else
        return search(root->right,key);
    }
    
};