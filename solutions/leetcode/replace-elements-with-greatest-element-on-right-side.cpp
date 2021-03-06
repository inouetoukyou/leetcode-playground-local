// Created by yangminghang on 2021/3/6.

// Given an array arr, replace every element in that
// array with the greatest element among the elements
// to its right, and replace the last element with -1.
//
// After doing so, return the array.

#include "leetcode.h"

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) {
            return arr;
        }
        int greatest = arr[n - 1];
        arr[n - 1] = -1;
        for (int i = n - 2; i >= 0; --i) {
            auto t = arr[i];
            arr[i] = greatest;
            if (t > greatest) {
                greatest = t;
            }
        }
        return arr;
    }
};

int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        if (s == "") {
            break;
        }
        auto arr = getVector(s);
        outputVector(solution.replaceElements(arr));
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
