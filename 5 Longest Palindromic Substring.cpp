class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        // int i = 0, j = s.length()-1;
        while (i < s.length() && j > 0 && i <= j) {
            if (s[i++] != s[j--]) {
                return false;
            }
        }
        return true;
    }
    
    

        
    string longestPalindrome(string s) {
        int maxLen = 0, start = 0;
        for (int i = 0; i < s.length(); i++) {
            for (int j = s.length()-1; j >= 0; j--) {
                if (isPalindrome(s, i, j) && j-i+1 >= maxLen) {
                    start = i;
                    maxLen = j-i+1;
                }
            }
        }
        // cout << start << maxLen;
        return s.substr(start, maxLen);

    }
};

// special case£º 1. Input: "ac", Output: "", Expected: "a"
// 2. Input: "abb", Output: "a", Expected: "bb"

// TIME LIMIT EXCEED!!! 
