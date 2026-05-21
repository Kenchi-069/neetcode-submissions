class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;
        for(string s : strs){
            encoded += '#' + to_string(s.size()) + '#' + s;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        for(int i(0); i<s.size();){
            i++;
            string st;
            while(s[i] != '#' && i<s.size()){
                st += s[i++];
            }
            int num = stoi(st);
            i++;
            string str;
            for(int j(0); j<num; j++){
                str+=s[i+j];
            }
            i+=num;
            decoded.push_back(str);
        }
        return decoded;
    }
};
