class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> group;
        vector<vector<string>> ans;
        // set<char> letters;
        for (int i = 0; i < strs.size(); i++) {
            string letters;
            for (int j = 0; j < strs[i].size(); j++) {
                letters = strs[i];
                sort(letters.begin(), letters.end());
            }
            group[letters].push_back(strs[i]);
        }

        unordered_map<string, vector<string>>::iterator iter;
        for (iter = group.begin(); iter != group.end(); iter++) {
            ans.push_back(iter->second);
        }

        return ans;
    }
};
