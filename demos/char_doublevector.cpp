//
// Created by Minghang Yang on 2019-07-12.
//

#include <vector>
#include <iostream>
#include "../tools/vectortool"

using namespace std;
using namespace ymh;
using T = char;
using VectorGenerator = GenericVectorGenerator<T>;

int main() {
    string input = R"([["1","e",   "1"],["q",  "0",  "x"]])";
    vector<vector<char>> ans = VectorGenerator::getDoubleVector(input);
    for (vector<char> &an : ans) {
        for (char &a : an) {
            cout << a << " ";
        }
        cout << endl;
    }
    /*
     * output
     * 1 e 1
       q 0 x */
    return 0;
}