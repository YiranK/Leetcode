class Solution {
public:
    static bool cmp(int x, int y) {
        string a = to_string(x), b = to_string(y);
        // cout << a << " " << b << endl;
        if (a.length() > b.length() && a.find(b) == 0 || a.length() < b.length() && b.find(a) == 0) {
            return a+b > b+a;
        } else {
            return a > b;
        }
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        for (int i = 0; i < nums.size(); i++) {
            // cout << nums[i];
            res += to_string(nums[i]);
        }
        // return to_string(stoi(res));
        if (count(res.begin(), res.end(), '0') == res.size()) return "0";
        return res;
    }
};


// Input:
// [121,12]
// Output:
// "12112"
// Expected:
// "12121"

// Input:
// [0,0]
// Output:
// "00"
// Expected:
// "0"

//Runtime Error Message:
// terminate called after throwing an instance of 'std::out_of_range'
//   what():  stoi
// Last executed input:
// [999999998,999999997,999999999]

// refine v2
 class Solution {
public:
    static bool cmp(int x, int y) {
        string a = to_string(x), b = to_string(y);
        
        // cout << a << " " << b << endl;
        // if (a.length() > b.length() && a.find(b) == 0 || a.length() < b.length() && b.find(a) == 0) {
        //     return a+b > b+a;
        // } else {
        //     return a > b;
        // }
        
        // [point1] no need to discuss different circumstances (like above), directly compare the string after concatenation.
        return a+b > b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string res = "";
        for (int i = 0; i < nums.size(); i++) {
            // cout << nums[i];
            res += to_string(nums[i]);
        }
        
        // [point2] transfer to int will result in out of range error
        // return to_string(stoi(res));
        
        // [point3] no need to count zero's number, for the first number is the biggest, if the first one is zero, then all left are zeros.
        // if (count(res.begin(), res.end(), '0') == res.size()) return "0";
        if (res[0] == '0') return "0";
        return res;
    }
};
