class Solution {
public:
    bool ifValid(string s) {
        set<char> dist(s.begin(), s.end());
        // for (int i = 0; i < s.length(); i++) {
        //     if ()
        // }
        return dist.size() <= 2;
    }
    
    int lengthOfLongestSubstringTwoDistinct(string s) {
        
/* MY WRONG IDEA AT FIRST:
Use a hashtable to denote the distinct two chars and their related count numbers.
But I forget that the count numbers are not consective counted,
which means even if I can substract count of most previous char,
the count of the remind char is more than the count when the remind char consectively exists before current one.

Instead, I should use the hashtable to denote the distinct two chars and their related rightmost exsiting position.
Thus, when I want to remove a char, I just need to set the left beginning position to the rightmost position of that char plus 1.
*/        
//         unordered_map<char, int> chars;
//         int count = 0, max = 0;
//         for (int i = 0; i < s.length(); i++) {
//             cout << "chars.size(): " << chars.size();
//             if (chars.find(s[i]) != chars.end() || chars.size() < 2) {
//                 if (chars.find(s[i]) != chars.end()) {
//                     cout << "  {find in chars}  ";
//                 } else {
//                     cout <<"  {chars.size() < 2}  ";
//                 }
//                 cout << "key-value pairs in char:";
//                 for (unordered_map<char, int>::iterator it = chars.begin(); it != chars.end(); it++) {        
//                         cout << "   " << it->first << "," << it->second;
//                 }
//                 chars[s[i]]++;
//                 count++;
//                 // cout << "  {not find in chars} s[i], count: " << s[i] << " " << count << endl;
//                 cout << "  count: " << count << endl;
//             } else {
//                 unordered_map<char,int>::iterator it = chars.begin();
//                 for (auto& x:chars) {
//                     if (x.first != s[i-1]) {
//                         count -= x.second;
//                         chars.erase(x.first);
//                         break;
//                     }
//                 }
//                 // count -= (chars.begin()+erase_pos)->second;
//                 // cout << 
//                 // chars.erase(chars.begin());
//                 chars[s[i]]++;
//                 count++;
//                 cout << "  {not find in chars} s[i], count: " << s[i] << " " << count << endl;
//             }
            
//             if (count > max) {
//                 max = count;
//             }
//         }
//         return max;
        
        // int dp[s.length()+1] = {0};
        int max = 0, i, j;
        if (s.length() == 1) return 1;
        for (i = 1; i < s.length(); i++) {
            for (j = i-1; j >= 0; j--) {
                // if (i == 10) {
                //     // cout << j << " " << s[j] <<" " << s.substr(j,i-j) <<" " << ifValid(s.substr(j, i-j+1)) << endl;
                // }
                if (!ifValid(s.substr(j, i-j+1))) {
                    // cout << "(i,j):" << i << "," << j << " - " << s.substr(j, i-j+1) << endl;
                    break;
                }
            }
            int len = i-j;
            if (len > max) max = len;
            // cout << "i: " << i << " s[i]:" << s[i] << " j: " << j << " max: " << max << endl;
        }
        return max;
    }
};


// corner case:
// Input:
// "a"
// Output:
// 0
// Expected:
// 1
