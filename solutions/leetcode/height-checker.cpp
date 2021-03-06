// Created by Minghang Yang on 2021/3/6.

// Students are asked to stand in non-decreasing
// order of heights for an annual photo.
//
// Return the minimum number of students that must
// move in order for all students to be standing in
// non-decreasing order of height.
//
// Notice that when a group of students is selected
// they can reorder in any possible way between
// themselves and the non selected students remain
// on their seats.

// example:
// Input: heights = [1,1,4,2,1,3]
// Output: 3
// Explanation:
// Current array : [1,1,4,2,1,3]
// Target array  : [1,1,1,2,3,4]
// On index 2 (0-based) we have 4 vs 1 so we have to move this student.
// On index 4 (0-based) we have 1 vs 3 so we have to move this student.
// On index 5 (0-based) we have 3 vs 4 so we have to move this student.

#include "leetcode.h"

using namespace std;

class Solution {
public:
    int heightChecker(vector<int> &heights) {
        int n = heights.size();
        if (n < 2) {
            return 0;
        }
        vector<int> sorted = heights;
        sort(sorted.begin(), sorted.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (heights[i] != sorted[i]) {
                ++ans;
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
        auto heights = getVector(s);
        cout << solution.heightChecker(heights) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
