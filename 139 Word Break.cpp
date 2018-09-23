class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        bool dp[s.length()] = {0};
        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j <= i; j++) {
                // cout << "j,i: " << j << " " << i << " s.substr: " << s.substr(j,i-j+1) << endl;
                
                // to check if substr [j, i] is in wordDict
                if (find(wordDict.begin(), wordDict.end(), s.substr(j, i-j+1)) != wordDict.end()) {
                    if (j == 0) {
                        dp[i] = true;
                    } else {
                        // to concat with the former word end with index of j-1
                        dp[i] = dp[i] || dp[j-1];
                    }
                }
            }
        }
        
        for (int i = 0; i < s.length(); i++) {
            // cout << dp[i] << endl;
        }
        return dp[s.length()-1];
    }
};