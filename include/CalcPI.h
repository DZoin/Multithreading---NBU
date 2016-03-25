#ifndef __Threading__CalcPI__
#define __Threading__CalcPI__

#include "CalcNode.h"

class CalcPI : public CalcNode
{
public:
    void operator()()
    {
        pi=0;
        double sum = 0.0,  // 1-1/3+1/5-1/7+1/9...
		term = 1.0,
		divisor = 1.0;

        int count;
        for (count = 1; count <= 1000000000;)
        {
            sum = sum + term;
            divisor = divisor + 2;
            ++count;

            if (count % 2 == 0) term = -1 / (divisor);
            else term = 1 / (divisor);
        }
        pi = 4 * sum;
    }
    double result()
    {
        return pi;
    }
private:
    double pi;
};

#endif
