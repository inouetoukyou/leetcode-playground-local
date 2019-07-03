//
// Created by Minghang Yang on 2019-06-29.
//

#ifndef OJ_VECTORTOOL_H
#define OJ_VECTORTOOL_H
#include <vector>
#include <string>
namespace ymh {
template <class T>
struct GenericVectorGenerator {
private:
    static void getSingleVectorPreprocess(std::string &input, std::string &forStringstream);
public:
    static std::vector<T> getSingleVector(std::string &input, char delim = ',', bool doPreprocess = true);

    static std::vector<std::vector<T>> getDoubleVector(std::string &input, char delim = ',');
};

}
#endif //OJ_VECTORTOOL_H
