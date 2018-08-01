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



// better sulotion
class Solution {
public:
    void swap(int low, int high, vector<int>& nums) {
        int tmp = nums[low];
        nums[low] = nums[high];
        nums[high] = tmp;
    }
    
    void debug(int i, vector<int> nums, string s) {
         cout << "i = " << i;
        cout << "  " << s << ": ";
        for(int t = 0; t < nums.size(); t++) {
            cout << nums[t] << " ";
        }
        cout << endl;
    }
    
    
    void sortColors(vector<int>& nums) {
        int white = 0, blue = nums.size()-1;
        for (int i = 0; i <= blue; i++) {
            if (nums[i] == 0) {
                //debug(i, nums, "before swap");
                swap(i, white++, nums);
                //debug(i, nums, "after swap");
            } else if (nums[i] == 2) {
                swap(i--, blue--, nums);
            }
        }
    }
};


// pay attention:
// 1. notice that for 'i' traverse 'nums' from left to right, so the left before 'i' is sorted already and satisified with the requirements.
//    when I first think about this problem, I consider many situations and their classifiction is complex and hard to think.
//    Actually, there are not so many situations to consider, for [0, j], (k, nums.size()-1) are already sorted.
//    Also, [0, i] is sorted, and it's not possible that j>i, because we just sort 'i's objects, 
//    even though all of them are red, which means 'j' red objects, 'j' can't be more than 'i'.
// 2. notice that different flag meaning can result in different handle to these subscripts' increasement or decresement.
//    (for simplcity, 'j' and 'k' below stand for 'white' and 'blue' in code above.)
//    for example, in this solution, 'j' denotes the first white object (or first not red object, in the begining steps), 
//                 which means [0, j-1] are absolutely red. 'k' denotes that [k+1, nums.size()-1] are blue and already sorted.
//                 pay attention that: (1)'i' doesn't increase itself but 'white' increases after awap,
//                                     in sentence :if (nums[i] == 0) swap(i, j++, nums);
//                                     this is because [j, i-1] is already sorted, which means nums[j] must be white.
//                                     so after swap(i, j), it's not necessary to check nums[i]'s value, it's absolutely white.
//                                     (2) but in sentence: if (nums[i] == 2) swap(i--, blue--, nums);
//                                     'i' need to decrease, because nums[k] is not sorted already( nums[k]+1 is sorted),
//                                     and we need to check nums[k]'s color, which is nums[i] after swap.
