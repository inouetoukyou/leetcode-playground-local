#include <helper.h>
#include "subroutine_relative.h"
using namespace std;

class Solution {
public:
    static int minTimeToVisitAllPoints(vector<vector<int>>& points) {
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
        vector<vector<int>> points = getVector2(s);
        int ans = Solution::minTimeToVisitAllPoints(points);
        cout << ans << endl;
    }

    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, subroutine_relative);
}
