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


// O(1) space, 2018/08/25
class Solution {
public:
    void reverseString(string &s, int i, int j) {
        while (i >= 0 && j < s.length() && i <= j) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
            i++;
            j--;
        }
    }
    
    void reverseWords(string &s) {
        if (s == "") return;
        reverseString(s, 0, s.length()-1);
        
        int i = 0;
        while (i < s.length()) {
            if (s[i] != ' ') {
                break;
            } else {
                i++;
            }
        }
        s.erase(0, i);
        
        // error-prone: len-1
        i = s.length()-1;
        while (i >= 0) {
            if (s[i] != ' ') {
                break;
            } else {
                i--;
            }
        }
        // error-prone: erase
        s.erase(i+1, s.length()-i);
        
        // cout << s << endl;
        i = 0;

        while (i < s.length()) {

            if (i < s.length() && s[i] != ' ') {
                int start = i;
                while (i < s.length() && s[i] != ' ') i++;
                reverseString(s, start, i-1);
                // cout << "after ith reverse words: " << i << " th, " << s << endl;
            } else {
                int start = i;
                while (i < s.length() && s[i] == ' ') i++;
                if (i != start) s.replace(start, i-start, " ");
                // cout << "after replace spaces ith reverse words: " << i << " th, " << s << endl;
                i -= i-start-1;
            }
        }
    }
};

//Input:
// " 1"
// Output:
// "1 "
// Expected:
// "1"

