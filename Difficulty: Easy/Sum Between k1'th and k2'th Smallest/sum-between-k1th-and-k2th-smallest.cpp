class Solution {
  public:
    int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        // code here
        int r=arr.size()-1;
        priority_queue<int>p1;
        for(int i=0;i<k1;i++){
            p1.push(arr[i]);
        }
        for(int i=k1;i<=r;i++){
            if(arr[i]<p1.top()){
            p1.pop();
            p1.push(arr[i]);
            }
        }
        int a=p1.top();
        
        priority_queue<int>p2;
        for(int i=0;i<k2;i++){
            p2.push(arr[i]);
        }
        for(int i=k2;i<=r;i++){
            if(arr[i]<p2.top()){
            p2.pop();
            p2.push(arr[i]);
            }
        }
        int b=p2.top();
        p2.pop();
        int sum = 0;

       for(int i = k2 - 1; i > k1; i--) {
                   sum += p2.top();
                   p2.pop();
               }

        return sum;
    }
};