#include "custom.h"
using namespace std;

class Solution {
public:
    static int minTimeToVisitAllPoints(const vector<vector<int>>& points) {
        int ans = 0;
        int n = points.size();
        for (int i = 1; i < n; ++i) {
            int a = abs(points[i][0] - points[i - 1][0]);
            int b = abs(points[i][1] - points[i - 1][1]);
            ans += abs(a - b) + (a < b ? a : b);
        }
        return ans;
    }
};
int sub(){
    string s;
    while (getline(cin, s)) {
        cout << Solution::minTimeToVisitAllPoints(getVector2(s)) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, subroutineRelative);
}
