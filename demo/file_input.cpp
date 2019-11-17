//
// Created by Minghang Yang on 2019-07-19.
//

/*
 * this dome tests file input
 * it is a solution for lintcode 813. leetcode 1004. Largest Sum of Averages
 * link https://leetcode.com/problems/largest-sum-of-averages/
 *      https://www.lintcode.cn/problem/largest-sum-of-averages//
 */

#include "../helper.h"

#include <fstream>
using namespace std;

class Solution {
public:
    static double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        if (n == 0) {
            return 0.0;
        }
        vector<int> sum(n + 1);
        vector<double> dp(n + 1);
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + A[i];
            dp[i + 1] = sum[i + 1] * 1.0 / (i + 1);
        }
        for (int i = 2; i <= K; ++i) {
            for (int j = n; j >= i; --j) {
                for (int k = i - 1; k < j; ++k) {
                    dp[j] = std::max(dp[j], dp[k] + (sum[j] - sum[k]) * 1.0 / (j - k));
                }
            }
        }
        return dp[n];
    }
};
int main() {
    string input;
    ifstream in = ifstream("../../input/demo/file_input.in");
    getline(in, input);
    int K;
    in >> K;
    in.close();
    /*
     * hint:
     * if you want to read an integer then read a string,
     * in >> K            // read an integer
     * getline(in, input) // cut the '\n'
     * getline(in, input) // read a string*/
    
    vector<int> A = getVector(input);
    outputVector(A);
    cout << Solution::largestSumOfAverages(A, K);
    return 0;
}
