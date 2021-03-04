// Created by Minghang Yang on 2021/3/4.

// Given two sorted integer arrays nums1 and nums2,
// merge nums2 into nums1 as one sorted array.
//
// The number of elements initialized in nums1 and nums2
// are m and n respectively. You may assume that nums1
// has a size equal to m + n such that it has enough
// space to hold additional elements from nums2.
#include "leetcode.h"

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1;
        int k = m + n - 1;
        while (j >= 0) {
            if (i >= 0 && nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s)) {
        if (s == "//") {
            break;
        }
        if (s == "") {
            continue;
        }
        auto nums1 = getVector(s);
        int m;
        cin >> m;
        cin.ignore(1);
        getline(cin, s);
        auto nums2 = getVector(s);
        int n;
        cin >> n;
        cin.ignore(1);
        solution.merge(nums1, m, nums2, n);
        outputVector(nums1);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
