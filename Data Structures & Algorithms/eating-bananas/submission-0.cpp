class Solution {
    vector<int> pil;
    int n;
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        pil = piles;
        int mx = 0;
        n = piles.size();
        for(int i(0); i<n; i++){
            mx = max(mx, piles[i]);
        }
        int l = 1, r = mx;
        while(l <= r){
            int k = (l+r)/2;

            long long total = 0;
            for(int p : piles){
                total += ceil(static_cast<double>(p)/k);
            }
            if(total <= h){
                mx = k;
                r = k - 1;
            }
            else{
                l = k + 1;
            }
        }
        return mx;

    }
};
