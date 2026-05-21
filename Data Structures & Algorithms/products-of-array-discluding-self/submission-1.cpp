class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> forward(n);
        vector<int> backward(n);
        vector<int> ans(n);
        forward[0] = 1;
        backward[n-1] = 1;
        for(int i(1); i<n; i++){
            forward[i] = nums[i-1]*forward[i-1];
        }
        for(int i(n-2); i>=0; i--){
            backward[i] = nums[i+1]*backward[i+1];
        }
        for(int i(0); i<n; i++){
            ans[i] = forward[i]*backward[i];
        }
        return ans;
    }
};
