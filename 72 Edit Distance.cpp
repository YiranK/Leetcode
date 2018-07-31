class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();

        // the edit distance of first m source characters [0, m-1] to first n target characters [0, n-1].
        int dp[m+1][n+1] = {0}; // need to initialize dp[0][0] to be 0.

        // the edit distance of first 0 source characters to first x target characters is equal to x,
        // for the number of addition is x.
        // [error-prone] : 1. w2 initialized to be 1, for dp[0][0] is 0.
        //                 2. subscript of dp is different from that of word1 or word2, first x target characters are word2[0, x-1].
        //                 3. dp[0][w2] = w2, not (w2+1).
        for (int w2 = 1; w2 <= n; w2++) dp[0][w2] = w2;
        
        // the edit distance of first x source characters to first 0 target characters, is equal to x,
        // for the number of remove opertion is x.
        // [error-prone] : 1. w1 initialized to be 1, for dp[0][0] is 0.
        //                 2. subscript of dp is different from that of word1 or word2, first x source characters are word1[0, x-1].
        //                 3. dp[w1][0] = w2, not (w1+1).
        for (int w1 = 1; w1 <= m; w1++) dp[w1][0] = w1;
        
        
        
        for (int w1 = 1; w1 <= m; w1++) {
            for (int w2 = 1; w2 <=n; w2++) {
                if (word1[w1-1] == word2[w2-1]) {
                    // first w1 source characters(word1[1, w1-1]) to first w2 target characters(word2[1, w2-1]).
                    // [error-prone]: subscript of dp is different from that of word1 or word2.
                    dp[w1][w2] = dp[w1-1][w2-1];
                } else {
                    // [error-prone]: min(int a, int b) cannot handle 3 arguments.
                    // dp[w1-1][w2-1], for replace.
                    // dp[w1][w2-1], for insert.
                    // dp[w1-1][w2], for remove.
                    dp[w1][w2] = min(min(dp[w1-1][w2-1], dp[w1][w2-1]), dp[w1-1][w2])+1;
                }
            }
        }

        return dp[m][n];
    }
};
