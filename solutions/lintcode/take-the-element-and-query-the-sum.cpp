// Created by yangminghang on 2021/2/11.

// 1559. Take the element and query the sum
// Now you have n numbers, save them in the arr array.
// You need to select any two numbers and multiply them,
// ask the sum of all these possibilities is.
// Return the sum.The return value is modulo 1000000007.
#include "lintcode.h"

using namespace std;

class Solution {
private:
    static int mod;
public:
    /**
     * @param arr: the arr
     * @return: the sum
     */
    int takeTheElementAndQueryTheSum(vector<int> &arr) {
        int n = arr.size();
        if (n < 2) {
            return 0;
        }
        vector<long long> sum(n - 1);
        sum[n - 2] = arr[n - 1];
        for (int i = n - 2; i > 0; --i) {
            sum[i - 1] = sum[i] + arr[i];
        }
        long long ans = 0;
        for (int i = n - 2; i >= 0; --i) {
            ans = (ans + sum[i] % mod * arr[i]) % mod;
        }
        return int(ans);
    }
};
int Solution::mod = 1000000007;

int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        auto arr = getVector(s);
        cout << solution.takeTheElementAndQueryTheSum(arr) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
