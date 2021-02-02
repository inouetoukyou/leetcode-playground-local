#include "leetcode.h"

using namespace std;

class Solution {
public:
    static string convertToTitle(int n) {
        string ans;
        if (n < 1) {
            return ans;
        }
        while (n > 0) {
            int r = n % 26;
            if (r == 0) {
                r = 26;
            }
            ans += char('A' + r - 1);
            n = (n - 1) / 26;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int sub() {
    int n;
    while (cin >> n) {
        cout << Solution::convertToTitle(n) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub);
}
