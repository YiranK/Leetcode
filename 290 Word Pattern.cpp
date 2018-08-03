class Solution {
public:
    vector<string> split(string s) {
        vector<string> ans;
        int pos = s.find(' '), start = 0;
        while (pos != string::npos) {
            // cout << s.substr(start, pos-start) << " ";
            ans.push_back(s.substr(start, pos-start));
            
            start = pos+1;
            pos = s.find(' ', start);
        }
        ans.push_back(s.substr(start));   
        return ans;
    }
    
    bool wordPattern(string pattern, string str) {
        if (str.length() == 0) return false;
        unordered_map<char, string> p2s;
        unordered_map<string, char> s2p;
        
        vector<string> s = split(str);
        if (pattern.size() != s.size()) return false;
        
        for (int i = 0; i < pattern.length(); i++) {
            if (p2s.find(pattern[i]) == p2s.end() && s2p.find(s[i]) == s2p.end()) {
                p2s[pattern[i]] =  s[i];
                s2p[s[i]] = pattern[i];
            } else if (p2s.find(pattern[i]) != p2s.end() && s2p.find(s[i]) != s2p.end()
                      && p2s[pattern[i]] == s[i] && s2p[s[i]] == pattern[i]) {
                    continue;
            } else {
                return false;
            }
            
        }
        return true;
    }
};
