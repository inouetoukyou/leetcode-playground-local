// Created by yangminghang on 2020/10/17.
#include "leetcode.h"
#include <unordered_map>
using namespace std;

class Solution {
public:
    static vector<string> findRepeatedDnaSequences(const string &s) {
        vector<string> ans;
        int n = s.size();
        if (n < 10) {
            return ans;
        }
        unordered_map<string, bool> presentedTwice;
        for (int i = 0, end = n - 9; i < end; i++) {
            string dnaSequence = s.substr(i, 10);
            if (presentedTwice.find(dnaSequence) == presentedTwice.end()) {
                presentedTwice.insert({dnaSequence, false});
            } else if (!presentedTwice[dnaSequence]) {
                presentedTwice[dnaSequence] = true;
            }
        }
        ans.reserve(presentedTwice.size());
        for (auto &x : presentedTwice) {
            if (x.second) {
                ans.push_back(x.first);
            }
        }
        return ans;
    }
};

int sub() {
    string s;
    while (getline(cin ,s)) {
        outputVector(Solution::findRepeatedDnaSequences(s));
    }
    return 0;
}

int main(int argc, char **argv) {
    return subRoutine(argc, argv, sub);
}
