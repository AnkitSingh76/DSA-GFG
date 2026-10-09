class Solution {
public:
    vector<int> passedBy(int a, int &b) {
        a = a + 1;
        b = b + 2;

        return {a, b};
    }
};