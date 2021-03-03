// Created by Minghang Yang on 2021/3/3.

// Given an integer array nums sorted in non-decreasing order,
// return an array of the squares of each number sorted in non-decreasing order.
#include "leetcode.h"

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        auto n = nums.size();
        if (n == 0) {
            return {};
        }
        vector<int> ans;
        ans.reserve(n);
        if (nums[0] >= 0) {
            for (auto a : nums) {
                ans.push_back(a * a);
            }
        } else if (nums[n - 1] <= 0) {
            for (int i = n - 1; i >= 0; --i) {
                ans.push_back(nums[i] * nums[i]);
            }
        } else {
            auto finalNegativePos = 0;
            auto i = 0;
            while (i < n && nums[i] < 0) {
                ++i;
            }
            finalNegativePos = i - 1;
            auto left = finalNegativePos, right = i;
            while (left >= 0 || right < n) {
                if (left < 0) {
                    ans.push_back(nums[right] * nums[right]);
                    ++right;
                } else if (right == n) {
                    ans.push_back(nums[left] * nums[left]);
                    --left;
                } else {
                    if ((-nums[left]) > nums[right]) {
                        ans.push_back(nums[left] * nums[left]);
                        --left;
                    } else {
                        ans.push_back(nums[right] * nums[right]);
                        ++right;
                    }
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
        if (s == "") {
            break;
        }
        auto nums = getVector(s);
        outputVector(solution.sortedSquares(nums));
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
