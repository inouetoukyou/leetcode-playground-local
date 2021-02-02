#include <helper.h>
#include <unordered_map>
using namespace std;

FILE *fre;

__attribute((constructor))void before() {
#ifdef INPUT_FROM_FILE
    fre = freopen("../../../tests/test3.in", "r", stdin);
#endif
}

__attribute((destructor))void after() {
#ifdef  INPUT_FROM_FILE
    fclose(fre);
#endif
}

class Solution {
public:
    static vector<int> twoSum(const vector<int>& nums, int target) {
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
