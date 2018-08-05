class Solution {
public:
    bool isValid(string s) {
        stack<char> sta;
        // remember this initialize method.
        // other method: unordered_map<char, char>::value_type('(',')');  
        unordered_map<char, char> parenMap = {pair<char,char>('(',')'), pair<char,char>('[', ']'), pair<char,char>('{','}')};
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                sta.push(s[i]);
            } else {
                char leftParen = sta.top();
                sta.pop();
                if (parenMap[leftParen] != s[i]) return false;
            }
        }
        
        // Open brackets must be closed by the same type of brackets.
        if (!sta.empty()) return false;
        return true;
    }
};
