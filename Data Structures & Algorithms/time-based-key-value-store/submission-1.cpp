class TimeMap {
private:
    unordered_map<string,vector<pair<int,string>>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].emplace_back(timestamp,value);
    }
    
    string get(string key, int timestamp) {
        auto& vals = mp[key];
        int left = 0, right = vals.size()-1;
        string res = "";
        while(left <= right){
            int mid = left + (right-left)/2;
            if(vals[mid].first <= timestamp) {
                res = vals[mid].second;
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        return res;
    }
};
