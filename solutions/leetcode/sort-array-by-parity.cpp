// Created by yangminghang on 2021/3/6.

// Given an array A of non-negative integers, return an array
// consisting of all the even elements of A, followed by all
// the odd elements of A.
//
// You may return any answer array that satisfies this condition.

#include "leetcode.h"

using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int> &A) {
        int n = A.size();
        if (n == 0) {
            return A;
        }
        int evenIndex = 0;
        for (int oddIndex = 0; oddIndex < n; ++oddIndex) {
            if (A[oddIndex] % 2 == 0) {
                swap(A[evenIndex], A[oddIndex]);
                ++evenIndex;
            }
        }
        return A;
    }

    vector<int> sortArrayByParity2(vector<int> &A) {
        int n = A.size();
        if (n == 0) {
            return A;
        }
        int i = 0, j = n - 1;
        while (i < j) {
            auto t1 = A[i] % 2, t2 = A[j] % 2;
            if (t1 == 1 && t2 == 0) {
                swap(A[i], A[j]);
            }
            if (t1 == 0) {
                ++i;
            }
            if (t2 == 1) {
                --j;
            }
        }
        return A;
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
        outputVector(solution.sortArrayByParity(nums));
        outputVector(solution.sortArrayByParity2(nums2));
        cout << '\n';
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
