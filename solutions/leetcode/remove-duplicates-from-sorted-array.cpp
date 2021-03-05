// Created by Minghang Yang on 2021/3/5.

// Given a sorted array nums, remove the
// duplicates in-place such that each element
// appears only once and returns the new length.
//
// Do not allocate extra space for another array,
// you must do this by modifying the input array
// in-place with O(1) extra memory.

#include "leetcode.h"

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int i = 0;
        for (int j = i + 1; j < n; ++j) {
            if (nums[j] != nums[i]) {
                nums[i + 1] = nums[j];
                ++i;
            }
        }
        return i + 1;
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
        auto n = solution.removeDuplicates(nums);
        cout << "len:" << n << endl;
        for (int i = 0; i < n; ++i) {
            cout << nums[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
