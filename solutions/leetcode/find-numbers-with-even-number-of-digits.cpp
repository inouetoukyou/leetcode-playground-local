// Created by yangminghang on 2021/3/3.

#include "leetcode.h"

using namespace std;

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        auto ans = 0;
        for (auto n : nums) {
            auto t = 0;
            do {
                ++t;
                n /= 10;
            } while (n > 0);
            if (t % 2 == 0) {
                ++ans;
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
        cout << solution.findNumbers(nums) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
