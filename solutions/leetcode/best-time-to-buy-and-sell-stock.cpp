// Created by Minghang Yang on 2021/1/3.

// 121. Best Time to Buy and Sell Stock
// Say you have an array for which the ith element is the price of a given stock on day i.
//
// If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), design an algorithm to find the maximum profit.
//
// Note that you cannot sell a stock before you buy one.
#include "leetcode.h"

using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int ans = 0;
        int min = prices[0];
        for (int i = 1; i < n; ++i) {
            if (prices[i] < min) {
                min = prices[i];
            } else {
                auto price = prices[i] - min;
                if (price > ans) {
                    ans = price;
                }
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
        cout << solution.maxProfit(prices) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
