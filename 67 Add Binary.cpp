class Solution {
public:
    string addBinary(string a, string b) {
        int len1 = a.length(), len2 = b.length();
        int len = max(len1, len2);
        if (len1 > len2) {
            b.insert(0, len1-len2, '0');
        } else {
            a.insert(0, len2-len1, '0');
        }

        string ans;
        int advance = -1, num;
        for (int i = len-1; i >= 0; i--){
            num = (a[i]-'0') ^ (b[i]-'0');
            if (advance != -1) num ^= advance;
            advance = (a[i]-'0') & (b[i]-'0') & advance;
            
            char in = num+'0';
            ans.insert(0, 1, in);
        }
        cout << advance;
        if (advance != 0) ans.insert(0, 1, advance+'0');
        
        return ans;
    }
};
