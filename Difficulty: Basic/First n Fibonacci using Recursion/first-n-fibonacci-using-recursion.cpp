class Solution {
  public:
    vector<int> fibonacciNumbers(int n) {
        // code here
        vector<int>ans;
        int first=0,second=1,next;
        for(int i=1;i<=n;i++){
            ans.push_back(first);
            next=first+second;
            second=first;
            first=next;
        }
        return ans;
    }
};