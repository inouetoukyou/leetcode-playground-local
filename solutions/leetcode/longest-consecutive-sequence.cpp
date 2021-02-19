// Created by yangminghang on 2021/2/19.

// Given an unsorted array of integers nums,
// return the length of the longest consecutive elements sequence.
#include "leetcode.h"

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        auto n = nums.size();
        if (n < 2) {
            return n;
        }
        sort(nums.begin(), nums.end());
        int ans = 1;
        int i = 0;
        while (i < n) {
            auto tmpLen = 1;
            do {
                auto j = i + 1;
                while (j < n && nums[j] == nums[i]) {
                    ++j;
                }
                if (j < n && nums[j] - nums[i] == 1) {
                    i = j;
                    ++tmpLen;
                } else {
                    i = j;
                    break;
                }
            } while (i < n);
            if (tmpLen > ans) {
                ans = tmpLen;
            }
        }
        return ans;
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
        cout << solution.longestConsecutive(nums) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
