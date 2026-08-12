class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
            sum+=arr[i];
        
        
        long long ans=1LL*(n+2)*(n+1)/2;
        
        return ans-sum;
    }
};