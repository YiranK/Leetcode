class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // to denote map from char in "s" to char in "t".
        unordered_map<char,char> m;
        // to denote if the mapped char in "t" has already been occupied.
        unordered_map<char,bool> rm;
        for (int i = 0; i < s.length(); i++) {
            // if char s[i] has no map yet and wants to creat one.
            // first check if the mapped char in "t" has already been occupied, which means its value is "true".
            if (m.find(s[i]) == m.end()) {
                if (rm.find(t[i]) != rm.end() && rm[t[i]] == true) return false;
                // create map
                m[s[i]] = t[i];
                // mark mapped occupied
                rm[t[i]] = true;
            } else {
                // if map is not the previous one.
                if (m[s[i]] != t[i]) return false;
            }
            
        }
        return true;
    }
};
