class Solution {
public:
    string intToRoman(int num) {
        // cout <<3;
        int nums = num, cnt = 0;
        // cout <<2;
        while (nums) {
            nums /= 10;
            cnt++;
        }
        // cout << 1;
        vector<vector<char>> bitToRoman = {{'I','V'}, {'X','L'}, {'C','D'},{'M'}};
        for (int i = 0; i < bitToRoman.size(); i++) {
            cout << bitToRoman[i][0] << " ";
        }
        string ans;
        int bit;
        while (cnt--) {
            
            bit = num / int(pow(10, cnt));
            num = num % int(pow(10, cnt));
            // cout << "cnt: " << cnt << " bit : "<< bit << endl;
            
            if (bit == 9) {
                ans.append(string(1, bitToRoman[cnt][0])+
                           string(1, bitToRoman[cnt+1][0]));
            } else if (bit == 4) {
                ans.append(string(1, bitToRoman[cnt][0])+
                           string(1, bitToRoman[cnt][1]));
            } else {
                if (bit >= 5) {
                    ans.append(string(1, bitToRoman[cnt][1]));
                    bit -= 5;
                }
                ans.append(string(bit, bitToRoman[cnt][0]));
            }
        }
        
        return ans;
    }
};
