class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int maxc = 0, current = 1;
        for(int i(0); i<n; i++){
            if(!st.contains(nums[i]-1)){
                current = 1;
                while(st.contains(nums[i]+current)){
                    current++;
                }
                maxc = max(maxc, current);
            }
        }
        return maxc;
    }
};
