// Created by yangminghang on 2021/2/12.

// 714. Best Time to Buy and Sell Stock with Transaction Fee

// Your are given an array of integers prices,
// for which the i-th element is the price of a given stock on day i;
// and a non-negative integer fee representing a transaction fee.
//
// You may complete as many transactions as you like,
// but you need to pay the transaction fee for each sell transaction.
//
// You may not buy more than 1 share of a stock at a time
// (ie. you must sell the stock share before you buy again.)
//
// Return the maximum profit you can make.
#include "leetcode.h"

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int sell = 0, own = -prices[0];
        for (int i = 1; i < n; ++i) {
            tie(sell, own) = make_tuple(
                max(sell, own + prices[i] - fee),
                max(own, sell - prices[i]));
        }
        return sell;
    }

    int maxProfitGreedy(vector<int>& prices, int fee) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int buy = prices[0] + fee;
        int profit = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] + fee < buy) {
                // update `buy`
                buy = prices[i] + fee;
            } else if (prices[i] > buy) {
                // we can regret if there is a higher price
                profit += prices[i] - buy;
                buy = prices[i];
            }
        }
        return profit;
    }
};

int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        auto prices = getVector(s);
        if (prices == vector<int>{}) {
            break;
        }
        int fee;
        cin >> fee;
        cin.ignore(1);
        cout << solution.maxProfit(prices, fee) << ' ' <<
        solution.maxProfitGreedy(prices, fee) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
