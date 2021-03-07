// Created by yangminghang on 2021/2/19.

// Given an unsorted array of integers nums,
// return the length of the longest
// consecutive elements sequence.
#include "leetcode.h"
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
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

    int longestConsecutive2(vector<int> &nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int longestStreak = 1, currentStreak = 1;
        for (int i = 1; i < n; ++i) {
            if (nums[i] != nums[i - 1]) {
                if (nums[i] - nums[i - 1] == 1) {
                    ++currentStreak;
                } else {
                    if (currentStreak > longestStreak) {
                        longestStreak = currentStreak;
                    }
                    currentStreak = 1;
                }
            }
        }
        if (currentStreak > longestStreak) {
            longestStreak = currentStreak;
        }
        return longestStreak;
    }

    int longestConsecutive3(vector<int> nums) {
        unordered_set<int> s;
        for (auto a : nums) {
            s.insert(a);
        }
        int longestStreak = 0;
        for (int a : s) {
            if (s.find(a - 1) == s.end()) {
                int curNum = a;
                int curStreak = 1;
                while (s.find(curNum + 1) != s.end()) {
                    ++curStreak;
                    ++curNum;
                }
                if (curStreak > longestStreak) {
                    longestStreak = curStreak;
                }
            }
        }
        return longestStreak;
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
        auto nums2 = nums, nums3 = nums;
        cout << solution.longestConsecutive(nums) << " ";
        cout << solution.longestConsecutive2(nums2) << " ";
        cout << solution.longestConsecutive3(nums3) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
