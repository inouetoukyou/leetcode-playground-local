//
// Created by Minghang Yang on 2019-07-03.
//
#include <iostream>
#include "../tools/vectortool"
#include "../tools/stringtool"

using namespace std;
using namespace ymh;

#if __GNUC__ <= 6 && __GNUC__ >= 5
namespace ymh {
#endif

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

#if __GNUC__ <= 6 && __GNUC__ >= 5
//T stringToValue(const std::string &str) {
auto stringToValue(const std::string &str) -> Interval {
#else
auto ymh::stringToValue(const std::string &str) -> Interval {
#endif

    string tmp = str;
    trimLeftTrailing(tmp);
    stringstream s(tmp);
    getline(s, tmp, ',');
    int start = stringToValue<int>(tmp);
    getline(s, tmp, ',');
    int end = stringToValue<int>(tmp);
    return Interval(start, end);
}

#if __GNUC__ <= 6 && __GNUC__ >= 5
}
#endif

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

