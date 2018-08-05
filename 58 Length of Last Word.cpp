class Solution {
public:    
    int lengthOfLastWord(string s) {
        // first reduce blank spaces in the right.
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] != ' ') break;
            if (s[i] == ' ') {
                s = s.substr(0, s.size()-1);
            }
            
        }
        
        // cout << s << "1" << endl;
        
        // constantly find space from left to right
        int pos = s.find(' '), start = 0;
        while (pos != -1) {
            start = pos+1;
            
            pos = s.find(' ', start);
            // cout << pos << endl;
        }
        
        return s.length() - start;
    }
};


// 1. pay attention: if not found in string, the return value of 'string.find' is -1.

// 2. convert a single char to string: char c = 'a';
// (1) string str(1, c);   '1' denotes length of this single char.
// (2) string str; str.push_back(c);
// wrong way: string str = "" + c; it does not mean "concatenate the empty string with the character c", it means "the pointer to some copy of an empty string, advanced by the numeric value of c. by Massa in https://stackoverflow.com/questions/17201590/c-convert-from-1-char-to-string.

// 3. substr([start index], [substr length]).
//    find([looking up char or string], [start finding index]).

// 4. pay attention to the situation that the last word is followed by empty spaces. we first reduce the spaces in the right.


