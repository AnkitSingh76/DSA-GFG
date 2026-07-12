class Solution {
public:
    int linearsearch(vector<int>& arr, int x, int index) {
        if (index == arr.size())
            return -1;

        if (arr[index] == x)
            return index;

        return linearsearch(arr, x, index + 1);
    }

    int search(vector<int>& arr, int x) {
        return linearsearch(arr, x, 0);
    }
};