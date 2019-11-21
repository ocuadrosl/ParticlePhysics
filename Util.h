#ifndef UTIL_H
#define UTIL_H

#include <vector>
#include <cmath>

namespace util
{


inline float squaredLength( const std::vector<float>& input)
{

    float lengh=0.f;
    for(auto it=input.begin(); it!= input.end(); ++it)
    {

        lengh += (*it) * (*it);
    }
    return lengh;

}

inline void normalize(const std::vector<float>& input, std::vector<float>& output)
{

    float length = std::sqrt(squaredLength(input));

    output = input;
    if(length == 1.f || length == 0.f) { return; }

    float scaleFactor = 1.f/length;

    for(auto it=output.begin(); it!= output.end(); ++it)
    {
        *it *= scaleFactor;
    }


}

}


#endif // UTIL_H
