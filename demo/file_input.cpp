//
// Created by Minghang Yang on 2019-07-19.
//

/*
 * this file file input
 * it is a solution for lintcode 813. leetcode 1004. Largest Sum of Averages
 * link https://leetcode.com/problems/largest-sum-of-averages/
 *      https://www.lintcode.cn/problem/largest-sum-of-averages//
 */

#include "../helper/vector_helper.h"

#include <fstream>
using namespace std;

class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        if (n == 0) {
            return 0.0;
        }
        vector<int> sum(n + 1);
        vector<vector<double>> dp(K + 1, vector<double>(n + 1));
        for (int i = 0; i < n; ++i) {
            sum[i + 1] = sum[i] + A[i];
            dp[1][i + 1] = sum[i + 1] * 1.0 / (i + 1);
        }
        for (int i = 2; i <= K; ++i) {
            for (int j = i; j <= n; ++j) {
                for (int k = i - 1; k < j; ++k) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][k] + (sum[j] - sum[k]) / (j - k));
                }
            }
        }
        return dp[K][n];
    }
};
int main() {
    string input;
    ifstream in = ifstream("../../input/demo/file_input.in");
    getline(in, input);
    int K;
    in >> K;
    in.close();
    vector<int> A = getVector(input);
    outputVector(A);
    cout << Solution().largestSumOfAverages(A, K);
    return 0;
}
