// Created by yangminghang on 2021/3/7.

// Given integer array nums, return the third
// maximum number in this array. If the third
// maximum does not exist, return the maximum number.

// example:
// Input: nums = [2,2,3,1]
// Output: 1
// Explanation: Note that the third maximum here means
// the third maximum distinct number.
// Both numbers with value 2 are both considered as
// second maximum.

#include "leetcode.h"

using namespace std;

class Solution {
public:
    int thirdMax(vector<int> &nums) {
        vector<int> can(3, INT_MIN);
        int cnt = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (nums[i] > can[0]) {
                can[2] = can[1];
                can[1] = can[0];
                can[0] = nums[i];
                ++cnt;
            } else if (nums[i] == can[0]) {
                if (nums[i] == INT_MIN) {
                    ++cnt;
                }
                continue;
            } else if (nums[i] > can[1]) {
                can[2] = can[1];
                can[1] = nums[i];
                ++cnt;
            } else if (nums[i] == can[1]) {
                if (nums[i] == INT_MIN) {
                    ++cnt;
                }
                continue;
            } else if (nums[i] > can[2]) {
                can[2] = nums[i];
                ++cnt;
            } else if (nums[i] == can[2] && nums[i] == INT_MIN) {
                ++cnt;
            }
        }
        if (cnt >= 3) {
            return can[2];
        } else {
            return can[0];
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
        cout << solution.thirdMax(nums) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
