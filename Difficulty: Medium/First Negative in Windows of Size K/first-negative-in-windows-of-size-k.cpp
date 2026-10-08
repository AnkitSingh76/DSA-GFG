class Solution {
  public:
  int display(queue<int>q){
      while(!q.empty()){
          if(q.front()<0)
          return q.front();
          
          q.pop();
      }
      return 0;
  }
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        queue<int>q;
        for(int i=0;i<k-1;i++){
            if(arr[i]<0)
            q.push(i);
        }
        vector<int>ans;
        for(int i=k-1;i<n;i++){
            if(arr[i]<0)
            q.push(i);
            
            if(q.empty())
            ans.push_back(0);
            
            else{
            if(q.front()<=i-k)
            q.pop();
            
            if(q.empty())
            ans.push_back(0);
            else
            ans.push_back(arr[q.front()]);
            }
        }
        return ans;
    }
};