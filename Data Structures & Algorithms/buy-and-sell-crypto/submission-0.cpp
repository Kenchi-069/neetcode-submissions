class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int r = prices.size()-1;
        int ans = 0, minl = prices[0];
        for(int i(1); i<r+1; i++){
            ans = max(ans, prices[i] - minl);
            minl = min(minl, prices[i]);
        }
        return ans;
    }
};
