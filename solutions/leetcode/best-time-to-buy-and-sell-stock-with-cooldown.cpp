// Created by Minghang Yang on 2021/1/13.

// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
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
        vector<int> peak, valley;
        int i = 0;
        while (i < n) {
            int cur = prices[i];
            ++i;
            while (i < n && prices[i] <= cur) {
                ++i;
            }
            valley.push_back(i - 1);
            cur = prices[i];
            ++i;
            while (i < n && prices[i] > cur) {
                ++i;
            }
            peak.push_back(i - 1);
        }
        int pn = peak.size();
        int vn = valley.size();
        n = pn < vn ? pn : vn;
        int ans = 0;
        if (n == 0) {
            return ans;
        }
        for (i = 0; i < n - 1; ++i) {
            if (peak[i] + 1 < valley[i + 1]) {
                ans += prices[peak[i]] - prices[valley[i]];
            } else {

            }
        }
        ans += prices[peak[n - 1]] - prices[valley[n - 1]];
        return ans;
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
