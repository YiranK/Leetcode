// time complexity: O(n^2), space complexity: O(1).
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int max_profit = 0, cur_profit = 0;

        for (int buyDay = 0; buyDay < prices.size()-1; buyDay++) {
            cur_profit = prices[buyDay+1] - prices[buyDay];
            //cout << "buyday, buyday+1: " << buyDay <<  " profit: " << cur_profit << endl;
            if (cur_profit > max_profit) max_profit = cur_profit;
            
            for (int sellDay = buyDay+2; sellDay < prices.size(); sellDay++) {
                cur_profit += prices[sellDay] - prices[sellDay-1];
                if (cur_profit > max_profit) max_profit = cur_profit;
            }
        }
        
        return max_profit;
    }
};



// time complexity: O(n), space complexity: O(1).
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;
        int max_profit = 0, cur_profit = 0;
        int smallest = prices[0];

        // find the max difference of highest with previous smallest valley.
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < smallest) smallest = prices[i];
            if (prices[i]-smallest > max_profit) max_profit = prices[i]-smallest;
        }
        
        return max_profit;
    }
};

// error-prone point: 'i < prices.size()', not 'i < prices.size()-1'
