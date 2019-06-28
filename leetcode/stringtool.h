#ifndef OJ_STRINGTOOL_H
#define OJ_STRINGTOOL_H

#include <string>
namespace ymh {
void trimLeftTrailingSpaces(std::string &input);

void trimRightTrailingSpaces(std::string &input);

template<class T>
auto stringToValue(const std::string &str) -> T;
}
#endif //OJ_STRINGTOOL_H
