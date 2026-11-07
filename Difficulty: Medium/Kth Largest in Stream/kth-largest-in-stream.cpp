class Solution {
public:
    vector<int> kthLargest(vector<int>& arr, int k) {

        vector<int> ans;
        int r=arr.size();
        priority_queue<int, vector<int>, greater<int>> p;
        for(int i = 0; i < r; i++) {
            if(p.size() < k) {
                p.push(arr[i]);
            }
            else if(arr[i] > p.top()) {
                p.pop();
                p.push(arr[i]);
            }
            // If fewer than k elements are present
            if(p.size() < k) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(p.top());
            }
        }
        return ans;
    }
};