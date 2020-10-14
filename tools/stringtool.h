#ifndef OJ_STRINGTOOL_H
#define OJ_STRINGTOOL_H

#include <string>
namespace ymh {
/*
 * trim if it is not digit*/
void trimLeftTrailing(std::string &input);
/*
 * trim if it is not digit*/
void trimRightTrailing(std::string &input);
/*
 * trim if it is space*/
void trimLeftTrailingSpaces(std::string &input);
/*
 * trim if it is space*/
void trimRightTrailingSpaces(std::string &input);

template<class T>
#if __GNUC__ >= 5 && __GNUC__ <= 6
T stringToValue(const std::string &str);
#else
auto stringToValue(const std::string &str) -> T;
#endif
/* convert string to int/double/long/float/long long/... by given T
 * */
}
#endif //OJ_STRINGTOOL_H
