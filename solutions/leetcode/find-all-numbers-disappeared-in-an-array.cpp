// Created by yangminghang on 2021/3/7.

// Given an array of integers where 1 ≤ a[i] ≤ n
// (n = size of array), some elements appear twice
// and others appear once.
//
// Find all the elements of [1, n] inclusive that do
// not appear in this array.
//
// Could you do it without extra space and in O(n)
// runtime? You may assume the returned list does not
// count as extra space.

#include "leetcode.h"

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans;
        if (n == 0) {
            return ans;
        }
        for (int i = 0; i < n; ++i) {
            while (nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]) {
                swap(nums[nums[i] - 1], nums[i]);
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                ans.push_back(i + 1);
            }
        }
        return ans;
    }

// marking the elements as negative as we visit the index
// and then in the second traverse if the element in the
// list is not negative then that particular number(index+1)
// does not exists in the list
    vector<int> findDisappearedNumbers2(vector<int> &nums) {
        int n = nums.size();
        vector<int> ans;
        if (n == 0) {
            return ans;
        }

        for (int i = 0; i < n; ++i) {
            int t = abs(nums[i]) - 1;
            if (nums[t] > 0) {
                nums[t] *= -1;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
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
        auto nums2 = nums;
        outputVector(solution.findDisappearedNumbers(nums));
        outputVector(solution.findDisappearedNumbers2(nums2));
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
