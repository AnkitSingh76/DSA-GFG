/*
class Node {
   public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
} */



class Solution {
  public:
  
  bool check(vector<Node *>&visited, Node *curr){
    for(int i=0;i<visited.size();i++){
        if(visited[i]==curr)
        return 1;
        
        
        else
        return 0;
    }
}
    bool detectLoop(Node* head) {
        // code here
        Node *curr=head;
        unordered_map<Node *,bool>visited;
        while(curr!=NULL){
            if(visited[curr]==1)
            return 1;
            
        
            visited[curr]=1;
            curr=curr->next;
            
        }
        return 0;
        
    }
};