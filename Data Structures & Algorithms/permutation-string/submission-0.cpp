class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length(), n2 = s2.length();
        if(n1 > n2) return false;
        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);
        for(int i(0); i<n1; i++) {
            freq1[s1[i]-'a']++;
            freq2[s2[i]-'a']++;
        }
        int matches = 0;
        for(int i(0); i<26; i++) {
            if(freq1[i] == freq2[i]) matches++;
        }
        int l = 0;
        for(int r(n1); r<n2; r++){
            if(matches == 26) return true;
            int index = s2[r] - 'a';
            freq2[index]++;
            if(freq1[index] == freq2[index]){
                matches++;
            } else if(freq1[index] + 1 == freq2[index]){
                matches--;
            }

            index = s2[l] - 'a';
            freq2[index]--;
            if(freq1[index] == freq2[index]){
                matches++;
            } else if(freq1[index] - 1 == freq2[index]){
                matches--;
            }
            l++;
        }
        return matches == 26;   
    }
};
