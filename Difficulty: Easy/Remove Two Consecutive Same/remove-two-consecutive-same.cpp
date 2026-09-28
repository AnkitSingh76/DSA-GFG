class Solution {
  public:
    int removeConsecutiveSame(vector<string>& arr) {
        // code here
        stack<string>s;
        for(int i=0;i<arr.size();i++){
            if(s.empty()){
                s.push(arr[i]);
            }
            else if (arr[i]!=s.top()){
                s.push(arr[i]);
            }
            else
            s.pop();
        }
        return s.size();
    }
};