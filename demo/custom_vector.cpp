//
// Created by Minghang Yang on 2019-07-03.
//
#include <vector>
#include <iostream>
#include <sstream>
#include "../leetcode/vectortool"
#include "../leetcode/stringtool"

using namespace std;
using namespace ymh;

class Interval {
public:
    int start, end;
    Interval(int start, int end) {
        this->start = start;
        this->end = end;
    }
};
using T = Interval;
template<>
auto ymh::stringToValue(const std::string &str) -> Interval {
    string tmp = str;
    trimLeftTrailing(tmp);
    stringstream s(tmp);
    getline(s, tmp, ',');
    int start = stringToValue<int>(tmp);
    getline(s, tmp, ',');
    int end = stringToValue<int>(tmp);
    return Interval(start, end);
}

using VectorGenerator = GenericVectorGenerator<T>;
void output(vector<T> intervals) {
    for (T t : intervals) {
        cout << t.start << " " << t.end << endl;
    }
}
int main() {
    string input = "[(0,30),(5,10),(15,20)]";
    vector<T> intervals = VectorGenerator::getSingleVector(input, ')');
    output(intervals);
    return 0;
}

