// Time Limit Exceeded
// Last executed input: "seeslaveidemonstrateyetartsnomedievalsees"
class Solution {
public:
    void moveon(vector<vector<string>>& ans, vector<int>& partition, string s, int part_num, int start) {
        if (part_num == 0) {
            vector<string> cur;
            
            bool flag = true;
            if (partition.empty()) {
                string r_s(s.rbegin(), s.rend());
                //cout << "s:" << s <<"  r_s: " << r_s << " if not equal: " << (s!=r_s) << endl;
                if (s != r_s) {
                    flag = false;
                }
                cur.push_back(s);
                //cout << "partition.empty()";
            } else {
                // error-prone point: when partition.size() == 0, the for loop below could result in runtime error.
                //cout << "partition.size()-1: " << partition.size()-1 <<endl;
                // cout << "partition: ";
                // for (int i = 0; i < partition.size(); i++) {
                //     cout << partition[i] << " ";
                // }
                // cout << endl;
                
                string str, r_str;
                // part 0
                str.assign(s.begin(), s.begin()+partition[0]);
                r_str.assign(str.rbegin(), str.rend());
                if (str != r_str) flag = false;
                cur.push_back(str);
                //cout << "s:" << str <<"  r_s: " << r_str << " part 0 if not equal: " << (str!=r_str) << endl;
                
                
                // middle part
                for (int i = 0; i < partition.size()-1; i++) {
                    str.assign(s.begin()+partition[i], s.begin()+partition[i+1]);
                    r_str.assign(str.rbegin(), str.rend());
                    //cout << "s:" << str <<"  r_s: " << r_str << "part: " << i+1 <<" if not equal: " << (str!=r_str) << endl;
                    if (str != r_str) {
                        flag = false;
                        break;
                    }
                    cur.push_back(str);
                }
                
                 // last part
                str.assign(s.begin()+partition.back(), s.end());
                r_str.assign(str.rbegin(), str.rend());
                if (str != r_str) flag = false;
                cur.push_back(str);
                //cout << "s:" << str <<"  r_s: " << r_str << " last part if not equal: " << (str!=r_str) << endl;
            }
            if (flag) ans.push_back(cur);
        } else if (part_num) {
            for (int i = start; i < s.length(); i++) {
                partition.push_back(i);
                moveon(ans, partition, s, part_num-1, i+1);
                partition.pop_back();
                
                // for (int i = 0; i < partition.size(); i++) {
                //     cout << partition[i] << " ";
                // }
                // cout << endl;
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<int> partition;
        
        // if (s.length() == 0) {
        //     vector<string> cur={""};
        //     ans.push_back(cur);
        // }
        
        for (int i = 0; i < s.length(); i++) {
            //cout << "i:" << i << endl;
            moveon(ans, partition, s, i, 1);
        }
        return ans;
    }
};



// right answer 
#include <string>
class Solution {
public:
    // use two index, low and high to compare whether the values of symmetric position are equal or not.
    bool isPalindrome(string s, int low, int high) {
        while (low <= high) {
            if (s[low++] != s[high--]) return false;
        }
        return true;
    }
    
    void moveon(vector<vector<string>>& ans, vector<string>& partition, string s, int start) {
        // end condition: all string length in vector<string> 'partition' equals to string 's' length.
        int part_count = 0;
        for (int i = 0; i < partition.size(); i++) {
            part_count += partition[i].length();
        }
        if (part_count == s.length()) {
            ans.push_back(partition);
        } else {
            // notice that 'i' can be the same with 'start', for 'i' indicates 'high' index.
            // when 'low' index equals to 'high' index, there is a string of length 1.
            for (int i = start; i < s.length(); i++) {
                // restrict that s[start, i] to be Palindrome, or do not choose this 'i' to be current node.
                if (!isPalindrome(s, start, i)) continue;
                partition.push_back(s.substr(start, i-start+1));
                moveon(ans, partition, s, i+1);
                partition.pop_back();
            }
        }
    }
    
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> partition;

        moveon(ans, partition, s, 0);
        return ans;
    }
};
