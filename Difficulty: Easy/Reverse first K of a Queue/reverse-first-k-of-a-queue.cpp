class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        // code here
        if(k <= 0 || k > q.size())
          return q;
        stack<int>st;
        for(int i=0;i<k;i++){
            st.push(q.front());
            q.pop();
        }
        int n=q.size();
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
        for(int i=0;i<n;i++){
            q.push(q.front());
            q.pop();
        }
        return q;
        
    }
};