class Solution {
public:
    vector<int> nextGreater(vector<int> &arr) {

        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;

        for (int i = 0; i < 2 * n; i++) {

            int index = i % n;

            while (!st.empty() && arr[st.top()] < arr[index]) {
                ans[st.top()] = arr[index];
                st.pop();
            }

            if (i < n) {
                st.push(index);
            }
        }

        return ans;
    }
};