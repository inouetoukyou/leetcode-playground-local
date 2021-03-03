// Created by Minghang Yang on 2021/3/3.

// Given a fixed length array arr of integers,
// duplicate each occurrence of zero, shifting
// the remaining elements to the right.
//
// Note that elements beyond the length of the
// original array are not written.
//
// Do the above modifications to the input array
// in place, do not return anything from your function.
#include "leetcode.h"

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        auto n = arr.size();
        if (n == 0) {
            return;
        }
        auto zeroCount = 0;
        for (auto a : arr) {
            if (a == 0) {
                ++zeroCount;
            }
        }
        auto discardCount = 0;
        int i = n - 1;
        int pos = n - 1;
        for (; i >= 0 && discardCount < zeroCount; --i) {
            if (arr[i] == 0) {
                discardCount += 2;
                if (discardCount > zeroCount) {
                    arr[pos--] = 0;
                }
            } else {
                ++discardCount;
            }
        }

        for (; i >= 0 && pos >= 0; --i) {
            if (arr[i] != 0) {
                arr[pos--] = arr[i];
            } else {
                arr[pos--] = 0;
                arr[pos--] = 0;
            }
        }
        return;
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
        solution.duplicateZeros(arr);
        outputVector(arr);
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
