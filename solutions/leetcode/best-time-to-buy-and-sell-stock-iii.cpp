// Created by Minghang Yang on 2021/1/3.

// 123. Best Time to Buy and Sell Stock III
// Say you have an array for which the ith
// element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit.
// You may complete at most two transactions.
//
// Note: You may not engage in multiple transactions
// at the same time (i.e., you must sell the stock
// before you buy again).
#include "leetcode.h"
#include <set>
using namespace std;

class Solution {
public:
    /**
     * @param prices: Given an integer array
     * @return: Maximum profit
     */
    int maxProfit(vector<int> &prices) {
        vector<pair<int, int>> trans;
        trans.reserve(64);
        int n = prices.size();
        int i = 0;
        int valley, peak;
        int ans = 0;
        while (i < n - 1) {
            while (i < n - 1 && prices[i] >= prices[i + 1]) {
                ++i;
            }
            valley = prices[i];
            while (i < n - 1 && prices[i] <= prices[i + 1]) {
                ++i;
            }
            peak = prices[i];
            if (peak > valley) {
                trans.push_back({valley, peak});
            }
        }
        int nt = trans.size();
        if (nt == 0) {
            return ans;
        }
        if (nt == 1) {
            ans = trans[0].second - trans[0].first;
            return ans;
        }
        vector<int> profits_left, profits_right;
        profits_left.reserve(nt);
        profits_right.reserve(nt);
        profits_left.push_back(trans[0].second - trans[0].first);
        auto min = trans[0].first;
        for (i = 1; i < nt; ++i) {
            if (trans[i].first < min) {
                min = trans[i].first;
            }
            auto t = trans[i].second - min;
            if (t > profits_left[i - 1]) {
                profits_left.push_back(t);
            } else {
                profits_left.push_back(profits_left[i - 1]);
            }
        }
        auto max = trans[nt - 1].second;
        profits_right.push_back(trans[nt - 1].second - trans[nt - 1].first);
        auto j = 0;
        for (i = nt - 2; i >= 0; --i) {
            if (trans[i].second > max) {
                max = trans[i].second;
            }
            auto t = max - trans[i].first;
            if (t > profits_right[j]) {
                profits_right.push_back(t);
            } else {
                profits_right.push_back(profits_right[j]);
            }
            ++j;
        }
        ans = profits_left[nt - 1];
        for (i = 0; i < nt - 1; ++i) {
            auto t = profits_left[i] + profits_right[nt - 2 - i];
            if (t > ans) {
                ans = t;
            }
        }
        return ans;
    }

    int maxProfit2(vector<int> &prices) {
        // b1, b2 indicate first and second time to buy
        // s1, s2 indicate first and second time to sell
        int b1=INT_MIN,b2=INT_MIN;
        int s1=0,s2=0;
        for(int i = 0; i < prices.size(); ++i) {
            b1 = max(b1, -prices[i]);
            s1 = max(s1, b1 + prices[i]);
            b2 = max(b2, s1 - prices[i]);
            s2 = max(s2, b2 + prices[i]);
        }
        return s2;
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            break;
        }
        auto prices = getVector(s);
        cout << solution.maxProfit(prices) << " " << solution.maxProfit2(prices)<< endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
