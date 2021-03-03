// Created by Minghang Yang on 2021/3/3.

// Given a binary array,
// find the maximum number of consecutive 1s in this array.
#include "leetcode.h"

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = 0;
        int i = 0;
        int end = n - ans;
        while (i < end) {
            while (i < end && nums[i] == 0) {
                ++i;
            }
            if (i < end && nums[i + ans] == 1) {
                ++i;
                auto t = 1;
                while (i < n && nums[i] == 1) {
                    ++i;
                    ++t;
                }
                if (t > ans) {
                    ans = t;
                    end = n - ans;
                }
            } else {
                ++i;
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
        cout << solution.findMaxConsecutiveOnes(nums) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
