class Solution {
public:
    string addBinary(string a, string b) {
        // first complement to same max length.
        int len1 = a.length(), len2 = b.length();
        int len = max(len1, len2);
        if (len1 > len2) {
            b.insert(0, len1-len2, '0');
        } else {
            a.insert(0, len2-len1, '0');
        }


        string ans;
        // use 'advance' to denote carry bit
        int advance = -1, num;
        // since we have already complement strings to same length, it's easier to traverse them.
        for (int i = len-1; i >= 0; i--){
            num = (a[i]-'0') ^ (b[i]-'0');
            // if not the rightmost bit
            if (advance != -1) {
                num ^= advance;
                // [error-prone] any two of the three components equaling to '1' can result in carry bit.
                advance = (a[i]-'0') & advance | (b[i]-'0') & advance | (a[i]-'0') & (b[i]-'0');
            // special case: the rightmost bit
            } else {
                advance = (a[i]-'0') & (b[i]-'0');
            }
            
            char in = num+'0';
            // [error-prone] pay attention to ONE char inserted into a string, needed to point out '1' length in parameters.
            ans.insert(0, 1, in);
        }
        
        // [error-prone] the leftmost bit
        if (advance != 0) ans.insert(0, 1, advance+'0');
        
        return ans;
    }
};
