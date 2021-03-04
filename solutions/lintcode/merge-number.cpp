// Created by Minghang Yang on 2021/1/3.

// 791. Merge Number
// Given n numbers, now we need to merge n numbers into one number.
// And each time we can only select and merge two numbers a,b.
// Each merger needs to consume a+b energy. Output the minimum energy
// consumed by merging n numbers.
#include "lintcode.h"

using namespace std;

class Solution {
public:
    /**
     * @param numbers: the numbers
     * @return: the minimum cost
     */
    int mergeNumber(vector<int> &numbers) {
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq(numbers.begin(), numbers.end());
        while (pq.size() > 1) {
            auto a = pq.top();
            pq.pop();
            a += pq.top();
            pq.pop();
            ans += a;
            pq.push(a);
        }
        return ans;
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s)) {
        if (s.size() == 0) {
            break;
        }
        auto numbers = getVector(s);
        cout << solution.mergeNumber(numbers) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
