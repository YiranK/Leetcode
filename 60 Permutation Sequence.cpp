class Solution {
public:
    string getPermutation(int n, int k) {
        string ans = "";
        
        // k-th means the index is (k-1).
        k--;
        
        // calculate (n-1)! , and push available candidates into vector 'candidates'.
        int fac = 1;
        vector<int> candidates;
        for (int i = 1; i < n ; i++) {
            fac *= i;
            candidates.push_back(i);
        }
        candidates.push_back(n);
        
        
        int round = n;       
        // end condition: no number is available in vector 'candidates'.
        while (!candidates.empty()) {
            // notice that the number of complete cycle is 'cur_idx',
            // which means the next cycle is (cur_idx+1)-th cycle,
            // which means the index of next cycle is 'cur_idx',
            // which means the index of first number is 'cur_idx'.
            int cur_idx = k/fac;
            int remainder = k%fac;
            
            ans += to_string(candidates[cur_idx]);
            candidates.erase(candidates.begin()+cur_idx);
            
            
            // print
            // for (int i = 0; i < candidates.size() ; i++) {
            //     cout << candidates[i];
            // }
            // cout << " " << ans << endl;
            
            
            // update factorial by dividing current 'n' value, to prepare next loop.
            round--;
            if (round) fac/=round;
            
            k = remainder;
        }
        
        return ans;
        
    }
    
};
