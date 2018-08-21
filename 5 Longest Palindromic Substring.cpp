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


// DP
class Solution {
public:

    string longestPalindrome(string s) {
        queue<pair<int,int>> tovisit;
        for (int i = 0; i < s.length(); i++) {
            int st = i;
            while (i < s.length()-1 && s[i] == s[i+1]) i++;
            tovisit.push(make_pair(st, i));
        }
        
        int longest = 0, st = 0;
        while (!tovisit.empty()) {
            pair<int, int> interval = tovisit.front();
            tovisit.pop();
            int i = interval.first, j = interval.second;
            if (j - i + 1 > longest) {
                longest = j-i+1;
                st = i;
            }
            
            if (i <= j && i-1 >= 0 && j+1 < s.length() && s[i-1] == s[j+1]) {
                tovisit.push(make_pair(i-1, j+1));
            }
        }
        
        return s.substr(st, longest);
    }
};


