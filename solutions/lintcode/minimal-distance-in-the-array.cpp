//
// Created by Minghang Yang on 2021/1/1.
//

#include <helper.h>
#include <vector>
#include "subroutine_relative.h"
using namespace std;

void binary_search(vector<int> &a, int target, int &left, int &right) {
    int n = a.size();
    left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (a[mid] > target) {
            right = mid - 1;
        } else if (a[mid] < target) {
            left = mid + 1;
        } else {
            left = mid;
            right = mid;
            return;
        }
    }
    int t = right;
    right = left;
    left = t;
}

class Solution {
public:
    /**
     * @param a: array a
     * @param b: the query array
     * @return: Output an array of length `b.length` to represent the answer
     */
    vector<int> minimalDistance(vector<int> &a, vector<int> &b) {
        int n = b.size();
        int m = a.size();
        vector<int> ans;
        ans.reserve(n);
        if (n == 0 || m == 0) {
            return ans;
        }
        sort(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            // binary search 找到右边第一个大于等于的数和左边第一个小于等于的数
            int left, right;
            binary_search(a, b[i], left, right);
            if (left < 0) {
                ans.push_back(a[right]);
                continue;
            }
            if (right == m) {
                ans.push_back(a[left]);
                continue;
            }
            long long la = llabs((long long)b[i] - (long long)a[left]);
            long long ra = llabs((long long)a[right] - (long long)b[i]);
            if (ra < la) {
                ans.push_back(a[right]);
            } else {
                ans.push_back(a[left]);
            }
        }
        return ans;
    }
};

int sub() {
    string s;
    Solution solution;
    while (getline(cin, s)) {
        vector<int> a(std::move(getVector(s)));
        if (!getline(cin, s)) {
            return 0;
        }
        vector<int> b(std::move(getVector(s)));
        outputVector(solution.minimalDistance(a, b));
        cin.ignore(1); // eat '\n'
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, subroutineRelative);
}
