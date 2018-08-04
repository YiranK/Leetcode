class Solution {
public:
    static bool cmp(int& a, int& b) {
        return a >= b;
    }
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), cmp);
        return nums[k-1];
    }
};

class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
    
    void debug(vector<int>& nums) {
        for (int i : nums) {
            cout << " " << i;
        }
        cout << endl;
    }
    

    int findKthLargest(vector<int>& nums, int tar) {
        if (nums.empty()) return 0;
        
        int left = 0, right = nums.size()-1;
        while (left < right) {
            // choose the middle element as pivot.
            int mid = (left + right) / 2;
            int pivot = nums[mid];
            // swap to move pivot to the first position in current interval.
            swap(nums, left, mid);
            
            // cout << "after choose pivot: " << pivot;
            // debug(nums);
            
            // behind 'h' is the determined smaller intervals.
            int h = right, i = left+1;
            while (i <= h) {
                if (nums[i] >= pivot) {
                    i++;
                } else {
                    swap(nums, i, h);
                    h--;
                }
            }
            
            // put 'pivot' to the position according its ranking in the vector.
            swap(nums, left, h);
            
            // cout << "after divide into two parts: ";
            // debug(nums);
            
            if (tar-1 == h) {
                return pivot;
            } else {
                if (tar-1 < h) {
                    right = h-1;
                } else {
                    left = h+1;
                }
            }
            
            // cout << "next interval: " << left << " " << right << endl << endl;
            
            
        }
        
        return nums[left];
    }
};

// there's no need to set two pointers, for two pointers can divide three parts and can be used in problem:[set colors].
// we just set one pointer to denote one point which is perfectly before determined smaller heap.

// when only 2 elements left, if 'tar' equals to the index of the pivot we choosed, then it return.
// otherwise, after one of the two pointers moves, 'left' equals to 'right', 'while' loop terminates.
//            so after exiting the loop, we return 'nums[left]'.

// pay attention: k-th means index k-1.
