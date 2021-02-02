// Created by yangminghang on 2021/1/3.

// 453. Minimum Moves to Equal Array Elements
// Given a non-empty integer array of size n, find the minimum number of moves required to make all array elements equal, where a move is incrementing n - 1 elements by 1.
#include "leetcode.h"

using namespace std;

class Solution {
public:
    /**
     * @param nums: an array
     * @return: the minimum number of moves required to make all array elements equal
     */
    int minMoves(vector<int> &nums) {
        int n = nums.size();
        int min = INT_MAX;
        long long sum = 0;
        for (auto &num : nums) {
            sum += num;
            min = std::min(min, num);
        }
        return sum - (long long)min * n;
    }
};

int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            break;
        }
        auto nums = getVector(s);
        cout << solution.minMoves(nums) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
