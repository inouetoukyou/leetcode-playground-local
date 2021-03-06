// Created by yangminghang on 2021/3/6.

// Given an array nums, write a function to move all 0's to the end
// of it while maintaining the relative order of the non-zero elements.

#include "leetcode.h"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return;
        }
        int i = 0;
        for (int j = 0; j < n; ++j) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                ++i;
            }
        }
    }
};

int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        if (s == "") {
            break;
        }
        auto nums = getVector(s);
        solution.moveZeroes(nums);
        outputVector(nums);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
