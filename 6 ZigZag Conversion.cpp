class Solution {
public:
    string convert(string s, int rows) {
        if (rows == 1 || rows == 0 || s.length() <= rows) return s;
        int group = (rows*2-2);
        int i = 0;
        
        // notice grammer: initialize all strings in vector to be empty string.
        vector<string> rstring(rows, "");
        
        while (i < s.length()) {
            // cout << "i, i%group: "<< i << " " <<  i%group << endl;
            // error prone: devision by zero will occur error.
            while (i < s.length() && i%group < rows) {
                // notice grammer: string(n, char)
                rstring[i%group] += string(1, s[i]);
                // cout << "after: rstring[] " <<i%group << " " << rstring[i%group] << endl;
                i++;
            }
            
            
            while (i < s.length() && i%group >= rows) {
                // c += i%group - rows + 1;
                // notice grammer: string(n, char)
                rstring[group - i%group] += string(1, s[i]);
                i++;
            }
        }
        
        string res = "";
        for (int i = 0; i < rstring.size(); i++) {
            res += rstring[i];
        }
        
        return res;
        
    }
};

// special case:"PAYPALISHIRING", 1.   Error: devision by zero.
