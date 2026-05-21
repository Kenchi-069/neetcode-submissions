class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> temp(2001, 0);
        for(int n : nums){
            temp[n+1000]++;
        }
        priority_queue<pair<int, int>,
            vector<pair<int, int>>,
            function<bool(pair<int,int>, pair<int,int>)>> pq(
                [](pair<int,int> a, pair<int,int> b) {
                    return a.second < b.second;
                }
            );
        for(int i(0); i<2001; i++){
            pq.push({i-1000, temp[i]});
        }
        vector<int> ans(k,0);
        for(int i(0); i<k; i++){
            ans[i] = pq.top().first;
            pq.pop();
        }
        return ans;
    }
};
