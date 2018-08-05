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
                // [error-prone point] right bracket could occur without left bracket occurred before.
                // pay attention to every time you want to pop a container, first you need to check if the container is empty.
                if (sta.empty()) return false;
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

// [error-prone point] right bracket could occur without left bracket occurred before.
// pay attention to every time you want to pop a container, first you need to check if the container is empty.
