class Solution {
public:
    void reverseWords(string &s) {
        vector<string> words;
        int start;
        for (int i = 0; i < s.length(); i++) {
            while (i < s.length() && s[i] == ' ') i++;
            // [error-prone point] only if after blank spaces are non-space characters, we push them into vector.
            // so it's neccessary to check whether 'while' loop above terminates becasue of s[i] != ' ' or just because traverse termination.
            // be careful, cannot be checked by (s[i] != ' '), for string has a tail, sometimes like '\0'.
            if (i != s.length()) {
                int start = i;
                while (i < s.length() && s[i] != ' ') i++;
                // cout << start << " " << i <<  s.substr(start, i-start) << endl;
                words.push_back(s.substr(start, i-start));
            }
        }
        
        string r;
        for (int i = words.size()-1; i >= 0; i--) {
            r += words[i];
            r += string(1, ' ');
        }
        
        s = r.substr(0, r.size()-1);
    }
};


