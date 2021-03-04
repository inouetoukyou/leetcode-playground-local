// Created by Minghang Yang on 2021/1/4.

// 122. Best Time to Buy and Sell Stock II
// Say you have an array prices for which the ith
// element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit.
// You may complete as many transactions as you like
// (i.e., buy one and sell one share of the stock
// multiple times).
//
// Note: You may not engage in multiple transactions
// at the same time (i.e., you must sell the stock
// before you buy again).
#include "leetcode.h"

using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int i = 0, maxprofit = 0, valley, peak;
        int n = prices.size();
        while (i < n - 1) {
            while (i < n - 1 && prices[i] >= prices[i + 1])
                i++;
            valley = prices[i];
            while (i < n - 1 && prices[i] <= prices[i + 1])
                i++;
            peak = prices[i];
            maxprofit += peak - valley;
        }
        return maxprofit;
    }

    int maxProfit2(vector<int> &prices) {
        int n = prices.size();
        int ans = 0;
        for (int i = 1; i < n; ++i) {
            int t = prices[i] - prices[i - 1];
            if (t > 0) {
                ans += t;
            }
        }
        return ans;
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s)) {
        auto prices = getVector(s);
        auto a1 = solution.maxProfit(prices);
        auto a2 = solution.maxProfit2(prices);
        if (a1 != a2) {
            cout << "bad solutions!" << endl;
            break;
        }
        cout << a1 << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
