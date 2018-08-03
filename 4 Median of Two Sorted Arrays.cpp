// O(n) solution
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size(), i1 = 0, i2 = 0, k = 0;
        int n = (n1+n2)/2;
        vector<int> res(n1+n2);
        
        while (i1 < n1 && i2 < n2 && k <= n) {
            if (nums1[i1] < nums2[i2]) {
                res[k++] =  nums1[i1++];
            } else {
                res[k++] =  nums2[i2++];
            }
            
        }
        
        while (i1 < n1 && k <= n) {
            res[k++] = nums1[i1++];
        }
        
        while (i2 < n2 && k <= n) {
            res[k++] = nums2[i2++];
        }
        
        if ((n1+n2)%2 > 0) {
            return res[k-1];
        } else {
            return double(res[k-1]+res[k-2])/2;
        }
    }
};
