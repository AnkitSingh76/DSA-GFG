class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        
        // for smallest elememt we will make max heap
        int r=arr.size()-1;
        priority_queue<int>p;
        for(int i=0;i<k;i++){
            p.push(arr[i]);
        }
        for(int i=k;i<=r;i++){
            if(arr[i]<p.top()){
                p.pop();
                p.push(arr[i]);
            }
        }
        return p.top();
    }
};