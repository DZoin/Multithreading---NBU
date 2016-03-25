#ifndef __Threading__CalcNode__
#define __Threading__CalcNode__

class CalcNode
{
public:
    CalcNode(){}
    ~CalcNode(){}
    virtual void operator()() =0;
    virtual double result() =0;
};

#endif