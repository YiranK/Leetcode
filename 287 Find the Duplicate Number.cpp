class Solution {
public:

    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size()-1;
        
        while (low < high) {
            int mid = (low + high) / 2;
            int cnt = 0;

            for (int i : nums) {
                if (i <= mid)
                    cnt++;
            }
            
            // notice when 'cnt == mid'.
            if (cnt <= mid)
                low = mid + 1;
            else
                high = mid;
        }
        
        return low;
    }
};

// if you want to save time complexity, use binary search.
// the key point of binary search is to find the middle element, and divide other elements into two parts, 
// according to their values are larger of smaller than the middle element.

// in this problem, the vector is unsorted, and we can't use extra space to store each part of binary search.
// so try to use the relationship between element value and the number of elements.
// notice that if you have elements in [1, n], and they only occur once, 
// then the number of elements should be less than or equal to n.
// pay attention that there is only one duplicate number, which means when vector length fixed,
// one absent number stands for replacing itself with the duplicate number.
// so if the number of an array where each integer is between 1 and n is larger than n, this array must has the duplicate number.
// if the number is equal to n, we are not sure and need binary search again.
// if the number is less than n, it must has no duplicate number.

// error-prone points:
// 1. 'cnt' need clear to 0 every time.
// 2. every 'while' loop, we traverse elements in vector, not just the elements in [low, high],
//    so the standard length of [1, mid] is 'mid'. 'low' and 'high' just help us to determine 'mid'.
// 3. if (cnt <= mid). pay attention to the stuation when (cnt == mid).
//    notice that the length of vector is 1 more than the available number range in vector.
//    so if the duplicate number is in [1, mid], then the count of number in [1, mid] must be larger than 'mid',
//    and can't be equal to 'mid'. for even if some numbers of range [1, mid] are absent, they are replaced by the duplicate number,
//    for the number range and vector length are both restricted.

