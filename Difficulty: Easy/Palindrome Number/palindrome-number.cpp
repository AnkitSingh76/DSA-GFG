
class Solution {
public:
    bool isPalindrome(int n) {
        int num = abs(n);
        int original = num;
        int rev = 0;

        while (num > 0) {
            int rem = num % 10;
            rev = rev * 10 + rem;
            num /= 10;
        }

        return rev == original;
    }
};
