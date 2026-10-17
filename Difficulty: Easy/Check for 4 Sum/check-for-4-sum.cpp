class Solution {
  public:
    bool fourSum(vector<int>& arr, int x) {
        // code here
        sort(arr.begin(),arr.end());
        int n=arr.size();
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
            int find=x-arr[i]-arr[j];
       int start=j+1,end=n-1;
        while(start<end){
            if(arr[start]+arr[end]==find)
            return 1;
            
            else if(arr[start]+arr[end]<find)
            start++;
            
            else
            end--;
        }
    }
        }
    return 0;
    }
};