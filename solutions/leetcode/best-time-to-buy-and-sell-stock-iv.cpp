// Created by Minghang Yang on 2021/1/8.

// 188. Best Time to Buy and Sell Stock IV
// You are given an integer array prices where
// prices[i] is the price of a given stock on
// the ith day.
//
// Design an algorithm to find the maximum profit.
// You may complete at most k transactions.
//
// Notice that you may not engage in multiple
// transactions simultaneously (i.e., you must
// sell the stock before you buy again).
#include "leetcode.h"

using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k < 1) {
            return 0;
        }
        int n = prices.size();
        if (2 * k > n) {
            auto ans = 0;
            for (int i = 1; i < n; ++i) {
                int t = prices[i] - prices[i - 1];
                if (t > 0) {
                    ans += t;
                }
            }
            return ans;
        }
        vector<int> buy(k, INT_MIN);
        vector<int> sell(k);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < k; ++j) {
                if (j == 0) {
                    buy[j] = max(buy[j], -prices[i]);
                } else {
                    buy[j] = max(buy[j], sell[j - 1] - prices[i]);
                }
                sell[j] = max(sell[j], buy[j] + prices[i]);
            }
        }
        return sell[k - 1];
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s) && s != "") {
        auto k = stoi(s);
        if (!getline(cin, s) || s == ""){
            break;
        }
        auto prices = getVector(s);
        cout << solution.maxProfit(k, prices) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
