
class Solution {
public:
    int reverseBits(int n) {
        int ans = 0;

        while (n > 0) {
            int rem = n % 2;
            ans = ans * 2 + rem;
            n = n / 2;
        }

        return ans;
    }
};
