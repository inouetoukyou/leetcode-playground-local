// Created by Minghang Yang on 2021/3/5.

// Given an array of integers arr, return
// true if and only if it is a valid mountain array.
//
// Recall that arr is a mountain array if and only if:
//
// arr.length >= 3
// There exists some i with 0 < i < arr.length - 1 such that:
// arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
// arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

#include "leetcode.h"

using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) {
            return false;
        }
        int i;
        for (i = 1; i < n && arr[i] > arr[i - 1]; ++i) {
        }
        if (i == n || arr[i - 1] == arr[i]) {
            return false;
        }
        for (++i; i < n && arr[i] < arr[i - 1]; ++i) {
        }
        return i == n;
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s)) {
        if (s == "") {
            break;
        }
        auto arr = getVector(s);
        cout << boolalpha << solution.validMountainArray(arr) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
