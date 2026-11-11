class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for (int num : nums) {
            counts[num]++;
        }

        vector<pair<int, int>> countsSorted;
        for (const auto& kvp : counts) {
            countsSorted.push_back({kvp.second, kvp.first});
        }
        sort(countsSorted.rbegin(), countsSorted.rend());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(countsSorted[i].second);
        }
        return result;
    }
};
