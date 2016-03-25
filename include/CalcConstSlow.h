#ifndef __Threading__CalcConstSlow__
#define __Threading__CalcConstSlow__

#include "CalcNode.h"

class CalcConstSlow : public CalcNode
{
public:
    void operator()()
    {
        x = 7;
        for (int count = 1; count <= 1000000000; count++)
        {
            x /= 1.00000001;
        }
    }
    double result()
    {
        return x;
    }
private:
    double x;
};

#endif
