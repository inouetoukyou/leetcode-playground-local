// Created by Minghang Yang on 2021/1/22.

// Given an integer array nums, return the length of the longest strictly increasing subsequence.
//
// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

#include "leetcode.h"

using namespace std;

class Solution {
public:
    // O(n^2)
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        vector<int> dp(n, 1);
        int ans = dp[0];
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j] && dp[i] <= dp[j]) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
        return ans;
    }
    // O(nlog(n))
    int lengthOfLIS2(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        vector<int> dp(n, 1);
        int ans = dp[0];
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (nums[i] > nums[j] && dp[i] <= dp[j]) {
                    dp[i] = dp[j] + 1;
                }
            }
            if (dp[i] > ans) {
                ans = dp[i];
            }
        }
        return ans;
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s)) {
        auto nums = getVector(s);
        cout << solution.lengthOfLIS(nums) << ' '
        << solution.lengthOfLIS2(nums)
        << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
