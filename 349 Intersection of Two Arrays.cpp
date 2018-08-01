class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> ans;
        for (int i = 0; i < nums1.size(); i++) {
            while(i+1 < nums1.size() && nums1[i] == nums1[i+1]) i++;
            if (find(nums2.begin(), nums2.end(), nums1[i]) != nums2.end()) {
                ans.push_back(nums1[i]);
            }
        }
        return ans;
    }
};

// second solution: use set_intersection function, but not neccessary.
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        // if vector<int> intersect not initialized to be 10 contents, 
        // intersect.begin() in set_intersection will result in runtime error.
        // the 4th paramater in set_intersection must be vector<int>, not set<int>.
        vector<int> intersect;
        set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), back_inserter(intersect));
        //intersect.resize(iter-intersect.begin());
        // if do not want to resize, we can replace 'intersect.begin()' with 'back_insert(intersect)'.
        set<int> intersectRemoveDupicates(intersect.begin(), intersect.end());
        
        vector<int> ans;
        ans.assign(intersectRemoveDupicates.begin(), intersectRemoveDupicates.end());
        
        return ans;
    }
};
