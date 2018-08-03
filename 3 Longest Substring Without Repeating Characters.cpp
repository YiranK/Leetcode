class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0, max = 0;
        vector<char> letter;
        
        for (int i = 0; i < s.length(); i++) {
            // add a not duplicate char to vector
            vector<char>::iterator iter = find(letter.begin(), letter.end(), s[i]);
            if (iter == letter.end()) {
                letter.push_back(s[i]);
            } else {
                // if this letter has occurred before
                letter.erase(letter.begin(), iter+1);
                letter.push_back(s[i]);
              
            }
            if (letter.size() > max) max = letter.size();
        }
        
        return max;
    }
};

// sliding window
