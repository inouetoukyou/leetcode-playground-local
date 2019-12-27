//
// Created by Minghang Yang on 2019-07-18.
//
/*
 * this demo tests big input
 * it is a solution for lintcode 1015. leetcode 802. Find Eventual Safe States
 * link https://leetcode.com/problems/find-eventual-safe-states/
 *      https://www.lintcode.cn/problem/find-eventual-safe-states/
 * usage:
 * $ cat ../../../input/demos/big_input.in|./big_input */

#include <helper.h>

using namespace std;

class Solution {
    static bool dfs(vector<vector<int>> &graph, vector<int> &status, vector<int> &ans, int pos) {
        status[pos] = 1;
        int n = graph[pos].size();
        if (n == 0) {
            status[pos] = 2;
            ans.push_back(pos);
            return true;
        }
        for (int i = 0; i < n; ++i) {
            if (status[graph[pos][i]] == 0 && !dfs(graph, status, ans, graph[pos][i])) {
                return false;
            }
            else if (status[graph[pos][i]] == 1) {
                return false;
            }
        }
        status[pos] = 2;
        ans.push_back(pos);
        return true;
    }
public:
    /**
     * @param graph: a 2D integers array
     * @return: return a list of integers
     */
    static vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        // write your code here
        int m = graph.size();
        if (m == 0) {
            return {};
        }
        vector<int> ans;
        vector<int> status(m);
        for (int i = 0; i < m; ++i) {
            if (status[i] == 0) {
                dfs(graph, status, ans, i);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string input;
    cin >> input;
    vector<vector<int>> graph = getVector2(input);
    vector<int> ans = Solution::eventualSafeNodes(graph);
    outputVector(ans);
    return 0;
}
