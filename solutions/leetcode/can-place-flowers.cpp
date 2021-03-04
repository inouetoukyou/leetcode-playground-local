// Created by yangminghang on 2021/1/3.

// 605. Can Place Flowers
// You have a long flowerbed in which some of
// the plots are planted, and some are not.
// However, flowers cannot be planted in adjacent plots.
//
// Given an integer array flowerbed containing 0's and 1's,
// where 0 means empty and 1 means not empty, and an integer n,
// return if n new flowers can be planted in the flowerbed
// without violating the no-adjacent-flowers rule.
#include "leetcode.h"

using namespace std;

class Solution {
public:
    /**
     * @param flowerbed: an array
     * @param n: an Integer
     * @return: if n new flowers can be planted in it without violating the no-adjacent-flowers rule
     */
    bool canPlaceFlowers(vector<int> &flowerbed, int n) {
        if (n < 1) {
            return true;
        }
        int len  = flowerbed.size();
        int cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == len - 1 || flowerbed[i + 1] == 0)) {
                flowerbed[i] = 1;
                cnt++;
                if (cnt == n) {
                    return true;
                }
            }
        }
        return false;
    }
};

int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            break;
        }
        auto flowerbed = getVector(s);
        getline(cin, s);
        if (s.size() == 0) {
            break;
        }
        auto n = stoi(s);
        cout << solution.canPlaceFlowers(flowerbed, n) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
