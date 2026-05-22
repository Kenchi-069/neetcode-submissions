class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        int maxc = 0, current = 1;
        for(int i(0); i<n; i++){
            if(st.find(nums[i]-1) == st.end()){
                current = 1;
                while(st.find(nums[i]+current) !=  st.end()){
                    current++;
                }
                maxc = max(maxc, current);
            }
        }
        return maxc;
    }
};
