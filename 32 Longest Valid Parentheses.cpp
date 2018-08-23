// wrong answer 
class Solution {
public:
    void extendParen(string s, int i, int j, vector<pair<int,int>>& validIntervals) {
        while (i >= 0 && j < s.length()) {
            if (i-1>=0 && j+1<s.length() && s[i-1] == '(' && s[j+1] ==')') {
                i--;
                j++;
            } else if (i-2>=0 && s[i-2] == '(' && s[i-1] == ')') {
                    i -= 2;
            } else if (j+2<s.length() && s[j+1] == '(' && s[j+2] == ')') {
                    j += 2;
            } else {
                break;
            }
        }
        

        int low = i, high = j;
        vector<pair<int,int>>::iterator k;
        cout << "i, j:" <<  i << " - " << j << endl;
        for (k = validIntervals.begin(); k != validIntervals.end(); ) {
            if (!((*k).second+1 < i || j+1 < (*k).first)) {
                low = min(low, (*k).first);
                high = max(high, (*k).second);
                k = validIntervals.erase(k);
                // cout << "before combine the interval overlapped: " << (*k).first << " - " << (*k).second << endl;
            } else {
                k++;
            }
        }
        
        cout << "low, high:" <<  low << " - " << high << endl;
        validIntervals.push_back(make_pair(low, high));
    }
    
    int longestValidParentheses(string s) {
        int i = 0, maxlen = 0;
        // notice: do not initialize it to valid number.
        vector<pair<int,int>> validIntervals;
        pair<int, int> maxpair = make_pair(-1, -2);
        while (i < s.length()) {
            if (i+1 < s.length() && s[i] == '(' && s[i+1] == ')') {
                extendParen(s, i, i+1, validIntervals);
                // cout << inter.first << " - " << inter.second << endl;
                // // if intersect
                // // if (inter.second >= maxpair.first || inter.first <= maxpair.second) {
                // if (!(inter.second+1 < maxpair.first || maxpair.second+1 < inter.first)) {
                //     maxpair = make_pair(min(maxpair.first, inter.first), max(maxpair.second, inter.second));
                //     cout << "after combine: " << maxpair.first << " - " << maxpair.second << endl;
                // } else {
                //     if (inter.second - inter.first > maxpair.second - maxpair.first) {
                //         maxpair = inter;
                //     }
                // }
            }
            i++;
        }
        
        
        cout << "last intervals:\n";
        for (int k = 0; k < validIntervals.size(); k++) {
            cout << validIntervals[k].first << " - " << validIntervals[k].second << endl;
            if (validIntervals[k].second - validIntervals[k].first + 1 > maxlen) {
                maxlen = validIntervals[k].second - validIntervals[k].first + 1;
            }
        }
        
        return maxlen;
    }
};

// wrong answer:
// Input:
// ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())"
// Output:
// 44
// Expected:
// 132


class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.length() == 0) return 0;
        int dp[s.length()] = {0};
        for (int i = 0; i < s.length(); i++) {
            // if (i == 5) {
            //     bool a = s[i - dp[i-1] - 1] == '(';
            //     bool b = s[i-1] == ')' && s[i] == ')';
            //     bool c = i-1 >= 0 && i - dp[i-1] - 2 >= 0;
            //     cout << a << endl;
            //     cout << b << endl;
            //     cout << c << endl;
            // }
            if (i-1 >= 0 && s[i-1] == '(' && s[i] == ')') {
                if (i-2 >= 0) {
                    dp[i] = dp[i-2] + 2;
                } else {
                    dp[i] = 2;
                }
            } else if (i-1 >= 0 && s[i-1] == ')' && s[i] == ')' && s[i - dp[i-1] - 1] == '(') {
                if (i - dp[i-1] - 2 >= 0) {
                    dp[i] = dp[i - dp[i-1] - 2] + dp[i-1] + 2;
                } else {
                    dp[i] = dp[i-1] + 2;
                }

            }
        }
        
        int maxlen = 0;
        for (int i = 0; i < s.length(); i++) {
            // cout << dp[i] << " ";
            if (dp[i] > maxlen) {
                maxlen = dp[i];
            }
        }
        
        return maxlen;
    }
};

// special case:
// Input:
// "(()())"
// Output:
// 4
// Expected:
// 6
