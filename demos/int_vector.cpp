#include <helper.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
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
int main() {
    string s = "[2,7,11,15]";
    vector<int> nums = getVector(s);
    int target = 9;
    [[maybe_unused]] Solution solution;
    vector<int> ans = Solution::twoSum(nums, target);
    outputVector(ans);
    return 0;
}
