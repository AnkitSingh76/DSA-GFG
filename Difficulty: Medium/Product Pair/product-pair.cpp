
class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        sort(arr.begin(), arr.end());

        int start = 0, end = arr.size() - 1;

        while (start < end) {
            long long product = 1LL * arr[start] * arr[end];

            if (product == target) {
                return true;
            }
            else if (product < target) {
                start++;
            }
            else {
                end--;
            }
        }

        return false;
    }
};
