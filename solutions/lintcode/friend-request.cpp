// Created by yangminghang on 2021/1/3.

// 895. Friend Request
// Given an array Ages of length n, where the first i elements represent the age of the individual i.
// Find total number of friend requests sent by this n person. There are some requirements:
//
// if Age(B) <= (1/2)Age(A) + 7, A will not send a request to B.
// if Age(B) > Age(A), A will not send a request to B.
// if Age(B) < 100 and Age(A) > 100, A will not send a request to B.
// if it does not satisfy 1,2,3, then A will send a request to B

#include "lintcode.h"

using namespace std;

class Solution {
public:
    /**
     * @param ages: The ages
     * @return: The answer
     */
    int friendRequest(vector<int> &ages) {
        int n = ages.size();
        if (n < 2) {
            return 0;
        }
        sort(ages.begin(), ages.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int multi = 1; // 处理相同名字的情况。
            while (i + 1 < n && ages[i + 1] == ages[i]) {
                ++i;
                ++multi;
            }
            if (ages[i] > 100) { // A大于100
                int j = 0;
                while (ages[j] < 100) { // j是B第一个大于等于100的坐标
                    ++j;
                }
                int least = (ages[i] >> 1) + 7; // B至少要达到的值-1
                int k = j;
                while (ages[k] <= least) {
                    ++k;
                }
                // k是B达到最小的值时的坐标
                if (k < i) {
                    ans += (i - k) * multi;
                }
            }
            else {
                int least = ages[i] / 2 + 7;
                int k = 0;
                while (k < i && ages[k] <= least){
                    ++k;
                }
                // k是B达到最小的值时的坐标
                if (k < i) {
                    ans += (i - k) * multi;
                }
            }
        }
        return ans;
    }

    int friendRequest2(vector<int> &ages) {
        int ans = 0;
        for(int i = 0; i < ages.size(); i++) {
            for(int j = 0; j < ages.size(); j++) {
                if(i == j) {
                    continue;
                }
                int A = ages[i];
                int B = ages[j];
                if(B <= A && B > A / 2 + 7 && !(B < 100 && A > 100)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};

int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        auto ages = getVector(s);
        if (ages.size() == 0) {// use blank line to execute part of test
            break;
        }
        cout << solution.friendRequest(ages) << ' '
        << solution.friendRequest2(ages) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
