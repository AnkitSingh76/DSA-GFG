
class Solution {
  public:
    vector<long long> factorialNumbers(long long n) {
        vector<long long> ans;
        long long product = 1;

        for (long long i = 1; ; i++) {
            if (product > n / i)
                break;

            product = product * i;
            ans.push_back(product);
        }

        return ans;
    }
};
