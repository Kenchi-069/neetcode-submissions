class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;
        int n = s.size();
        int l = 0, maxm = 0, temp = 0;
        for(int r(0); r<n; r++){
            char c = s[r];
            freq[c]++;
            maxm = max(maxm, freq[c]);
            while((r-l+1)-maxm>k){
                freq[s[l]]--;
                l++;
            }
            temp = max(temp, r-l+1);
        }
        return temp;
    }
};
