#include <helper.h>
#include <unordered_set>
#include "subroutine_relative.h"

using namespace std;

class Solution {
public:
    static bool checkIfExist(const vector<int>& arr) {
        if (arr.empty()) {
            return false;
        }
        int n = arr.size();
        if (n == 1) {
            return false;
        }
        unordered_set<int> s;
        s.insert(arr[0]);
        for (int i = 1; i < n; ++i) {
            if (s.find(arr[i] * 2) != s.end()) {
                return true;
            }
            if (((unsigned int)arr[i] & 1u) == 0 && s.find(arr[i] / 2) != s.end()) {
                return true;
            }
            s.insert(arr[i]);
        }
        return false;
    }
};

int sub() {
    string s;
    while (getline(cin, s)) {
        cout << boolalpha << Solution::checkIfExist(getVector(s)) << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    return subRoutine(argc, argv, sub, subroutine_relative);
}
