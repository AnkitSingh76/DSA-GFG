class Solution {
public:
    vector<int> equalSum(vector<int>& arr) {
        int n = arr.size();
        int total = 0;

        for (int x : arr)
            total += x;

        int leftSum = 0;
        int bestX = INT_MAX;
        int bestPos = -1;
        int bestFlag = -1;

        for (int i = 0; i < n - 1; i++) {
            leftSum += arr[i];
            int rightSum = total - leftSum;


            if (rightSum >= leftSum) {
                int x = rightSum - leftSum;

                if (x < bestX) {
                    bestX = x;
                    bestPos = i + 2;
                    bestFlag = 1;
                }
            }

           
            if (leftSum >= rightSum) {
                int x = leftSum - rightSum;

                if (x < bestX) {
                    bestX = x;
                    bestPos = i + 2;
                    bestFlag = 2;
                }
            }
        }

        return {bestX, bestPos, bestFlag};
    }
};
