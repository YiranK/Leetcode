class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int dp[nums.size()] = {0};
        if (nums.empty()) return vector<int>();
        vector<int> res;
        int size = k % 2 == 1 ? nums.size()-k/2 : nums.size()-k/2+1;
        for (int i = k/2; i < size; i++) {
            int max_win = nums[i];
            for (int j = 1; j <= k/2; j++) {
                // odd number
                if (k % 2 || j <= k/2-1) {
                    max_win = max(max(max_win, nums[i-j]), nums[i+j]);
                } else {
                    // cout << i << " " << j << endl;
                    // if (i+j >= nums.size()) break;
                    max_win = max(max_win, nums[i-j]);
                }
                
            }
            res.push_back(max_win);
        }
        return res;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> cans;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            while (!cans.empty() && cans.front() < i-k+1) cans.pop_front();
            while (!cans.empty() && nums[cans.back()] < nums[i]) cans.pop_back();
            cans.push_back(i);
            if (i-k+1 >= 0) res.push_back(nums[cans.front()]);
        }
        return res;
    }
};
// double ended queue, Monotonic Queue
// before insert the new element in the tail of deque, first pop the elements smaller than it from the tail,
//     to ensure Monotonic in the deque
// O(n), one insert into deque and one pop from deque, per each element
// the time complexity of inserting or poping on deque head or deque tail is O(1)
// deque stores the index, not the value of element in vector nums