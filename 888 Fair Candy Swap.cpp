class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int sumA = 0, sumB = 0;
        // [GRAMMER] directly use vector to initialize set, no need to insert value one by one
        unordered_set<int> setA(A.begin(), A.end());
        for (int i = 0; i < A.size(); i++) {
            sumA += A[i];
        }
        for (int j = 0; j < B.size(); j++) {
            sumB += B[j]; 
        }
        // need to find a pair [a, b] so that a = b + (sumA-sumB)/2
        int diffAB = (sumA - sumB) / 2;
        
        // time compexity: O(n^2)
        // for (int i = 0; i < A.size(); i++) {
        //     for (int j = 0; j < B.size(); j++) {
        //         int exchange = B[j] - A[i];
        //         if (sumA+exchange == sumB-exchange) {
        //             return vector<int>({A[i], B[j]});
        //         }
        //     }
        // }
        
        for (int i = 0; i < B.size(); i++) {
            if (setA.count(B[i]+diffAB)) {
                // [GRAMMER] directly return vector in {}, without initialization
                return {B[i]+diffAB, B[i]};
            }
        }
        
        return vector<int>();
    }
};
