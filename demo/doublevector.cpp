//
// Created by Minghang Yang on 2019-06-29.
//
#include <vector>
#include <iostream>
#include <sstream>
#include "../leetcode/vectortool"

using namespace std;
using namespace ymh;
using T = int;
using VectorGenerator = GenericVectorGenerator<T>;

int main() {
    string input = "[[2,3,1],[7,5], [2] , [  45,32  , 543, 54,32] ]";
    vector<vector<int>> ans = VectorGenerator::getDoubleVector(input);
    for (vector<int> &an : ans) {
        for (int &a : an) {
            cout << a << " ";
        }
        cout << endl;
    }
    /*
     * output
     * 2 3 1
       7 5
       2
       45 32 543 54 32 */
    return 0;
}