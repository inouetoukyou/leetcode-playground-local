#include <helper.h>
#include <unordered_map>
using namespace std;

FILE *fre;
__attribute((constructor))void before() {
#ifdef LOCAL
    fre = freopen("../../input/test3.in", "r", stdin);
#endif
}
__attribute((destructor))void after() {
#ifdef  LOCAL
    fclose(fre);
#endif
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        int n = nums.size();
        if (n < 2) {
            return ans;
        }
        unordered_map<int, int> mp;
        for (int i = 0; i < n; ++i) {
            if (mp.find(target - nums[i]) != mp.end()) {
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
            else {
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string s;
    while (getline(cin, s)) {
        vector<int> nums = getVector(s);
        int target;
        cin >> target;
        getline(cin, s); // eat '\n'
        vector<int> ans = solution.twoSum(nums, target);
        outputVector(ans);
    }
    return 0;
}
