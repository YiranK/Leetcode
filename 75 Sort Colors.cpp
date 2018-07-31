class Solution {
public:
    void swap(int low, int high, vector<int>& nums) {
        int tmp = nums[low];
        nums[low] = nums[high];
        nums[high] = tmp;
    }
    
    
    void swapForwardOneStep(int& begin, int i, vector<int>& nums) {
        swap(i, begin, nums);
        begin++;
    }
    
    void swapForewardTwoStep(int& beginA, int& beginB, int i, vector<int>& nums) {
        swap(i, beginB, nums);
        swap(beginB, beginA, nums);
        beginA++;
        beginB++;
    }
    
    void sortColors(vector<int>& nums) {
        // red:[0, whiteBegin-1], white:[whiteBegin, blueBegin-1], blue:[blueBegin, nums.size()-1]
        // these 3 variables below indicate their position, and theirr occurances simultaneously.
        int redEnd=-1, whiteBegin=-1, blueBegin =-1;
        for (int i=0; i<nums.size(); i++) {
            // red, not in [0, whiteBegin-1]
            if (nums[i]==0) {
                if (redEnd < 0) redEnd = 0; // to indicate red exists.
                if (whiteBegin >= 0 && blueBegin >= 0){
                    // red in [whiteBegin, blueBegin-1]
                    // cout << "2step: " << whiteBegin << blueBegin << i;
                    swapForewardTwoStep(whiteBegin, blueBegin, i, nums);
                } else {
                    if (whiteBegin >= 0) {
                        swapForwardOneStep(whiteBegin, i, nums);
                    } else if (blueBegin >= 0) {
                        swapForwardOneStep(blueBegin, i, nums);
                    }
                } 
            // white
            } else if (nums[i] == 1) {
                // cout << blueBegin << " "<< nums[blueBegin] << " ";
                if (blueBegin >= 0) {
                    // cout << i << " "<< nums[i] << " swap between:\n" << blueBegin << " " << i;
                    swapForwardOneStep(blueBegin, i, nums);
                    if (whiteBegin < 0)
                        whiteBegin = blueBegin-1;
                } else {
                    if (whiteBegin < 0)
                        whiteBegin = i;
                }
                // cout << nums[i] << endl;
            } else {
                if (blueBegin < 0)
                    blueBegin = i;
 
            }
                    
        }
    }
};
