// Created by yangminghang on 2021/3/4.

// Given an array nums and a value val,
// remove all instances of that value in-place
// and return the new length.
//
// Do not allocate extra space for another array,
// you must do this by modifying the input array
// in-place with O(1) extra memory.
//
// The order of elements can be changed. It doesn't
// matter what you leave beyond the new length.
#include "leetcode.h"

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int i = 0, j = n - 1;
        while (i <= j) {
            while (i <= j && nums[j] == val) {
                --j;
            }
            while (i <= j && nums[i] != val) {
                ++i;
            }
            if (i <= j) {
                swap(nums[i], nums[j]);
                ++i;
                --j;
            }
        }
        return j + 1;
    }

    int removeElement2(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0;
        for (int j = 0; j < n; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }

    int removeElement3(vector<int>& nums, int val) {
        int i = 0;
        int n = nums.size();
        while (i < n) {
            if (nums[i] == val) {
                nums[i] = nums[n - 1];
                // reduce array size by one
                n--;
            } else {
                i++;
            }
        }
        return n;
    }
};

void output(vector<int> &nums, int len) {
    cout << len << ":";
    for (int i = 0; i < len; ++i) {
        cout << " " << nums[i];
    }
    cout << endl;
}


int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        if (s == "//") {
            break;
        }
        if (s == "") {
            continue;
        }
        auto nums = getVector(s);

        int val;
        cin >> val;
        cin.ignore(1);
        auto nums2 = nums;
        auto nums3 = nums;
        int len = solution.removeElement(nums, val);
        output(nums, len);
        len = solution.removeElement2(nums2, val);
        output(nums2, len);
        len = solution.removeElement3(nums3, val);
        output(nums3, len);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
