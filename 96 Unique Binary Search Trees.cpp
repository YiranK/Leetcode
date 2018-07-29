class Solution {
public:
    int numTrees(int n) {
        // record th nums of unique BST if 'i's nodes in the same side.
        vector<int> f = {1, 1, 2, 5};
        for (int x = 4; x <= n; x++) {
            int num = 0;
            for (int i = 0; i < x; i++) {
                num += f[i] * f[x-1 -i];
            }
            f.push_back(num);
        }
        
        return f[n];
    }
};
