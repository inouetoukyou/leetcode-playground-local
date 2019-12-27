#include "../helper.h"
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
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
int main(){
    Solution solution;
    string s = "[[1,1],[3,4],[-1,0]]";
    vector<vector<int>> points = getVector2(s);
    int ans = solution.minTimeToVisitAllPoints(points);
    cout << ans << endl;
    return 0;
}
