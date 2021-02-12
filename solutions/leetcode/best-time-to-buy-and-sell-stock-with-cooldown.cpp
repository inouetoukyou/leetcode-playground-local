// Created by Minghang Yang on 2021/1/13.

// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit.
// You may complete as many transactions as you like
// (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
//
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
// After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
#include "leetcode.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int f0, f1, f2; // f0: with stock, f1: without stock and during cooldown, f2: without stock and not during cooldown
        f0 = -prices[0];
        f1 = 0;
        f2 = 0;
        for (int i = 1; i < n; ++i) {
            tie(f0, f1, f2) = make_tuple(max(f0, f2 - prices[i]), f0 + prices[i], max(f1, f2));
        }
        return max(f1, f2);
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s)) {
        auto prices = getVector(s);
        cout << solution.maxProfit(prices) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
