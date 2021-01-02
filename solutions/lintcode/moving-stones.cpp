#include <helper.h>
#include "subroutine_relative.h"

using namespace std;

class Solution {
public:
    int movingStones(vector<int> &arr) {
        int n = arr.size();
        if (n == 0) {
            return 0;
        }
        std::sort(arr.begin(), arr.end());
        int ans_for_odd = 0, ans_for_even = 0;
        for (int i = 0, target = 1; i < n; ++i) {
            ans_for_odd += abs(arr[i] - target);
            ++target;
            ans_for_even += abs(arr[i] - target);
            ++target;
        }
        return min(ans_for_even, ans_for_odd);
    }
};

int sub() {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        vector<int> a = getVector(s);
        cout << solution.movingStones(a) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, subroutineRelative);
}
