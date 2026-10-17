
class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int, int> freq;

        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

      
        vector<pair<int, int>> v;

        for (auto it : freq) {
            v.push_back({it.second, it.first});
        }

       
        sort(v.begin(), v.end(), greater<pair<int, int>>());

        vector<int> ans;

        for (int i = 0; i < k && i < v.size(); i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
