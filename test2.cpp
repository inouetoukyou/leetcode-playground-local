//
// Created by Minghang Yang on 2020/1/6.
//

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
int sub() {
    string s;
    while (getline(cin, s)) {
        vector<int> nums = getVector(s);
        int target;
        cin >> target;
        getline(cin, s); // eat '\n'
        vector<int> ans = Solution::twoSum(nums, target);
        outputVector(ans);
    }
    return 0;
}
int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, "/../../input/");
}
