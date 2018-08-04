class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        
        string s = countAndSay(n-1);
        string ans = "";
        for (int i = 0; i < s.size(); i++) {
            char a = s[i];
            int cnt = 1;
            while (i+1 < s.size() && s[i+1] == a) {
                i++;
                cnt++;
            }
            ans += to_string(cnt);
            ans += a;
        }
        
        return ans;
    }
};
