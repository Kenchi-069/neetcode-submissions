class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(int n : nums){
            mp[n]++;
        }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto& [num, count] : mp){
            buckets[count].push_back(num);
        }
        vector<int> ans;
        for(int i(buckets.size()-1); i>=0 && ans.size() < k; i--){
            for(int n : buckets[i]){
                ans.push_back(n);
                if(ans.size() == k) break;
            }
        }
        return ans;
    }
};
