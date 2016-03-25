#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <pthread.h>

#include "CalcPI.h"
#include "CalcConstSlow.h"

using namespace std;

void * calc(void *data)
{
    CalcNode *node = reinterpret_cast<CalcNode*>(data);
    (*node)();
    // cout << " [" << result << "]" << endl;
    return NULL;
}

int main()
{   
    CalcNode *calc1 = new CalcPI();
    CalcNode *calc2 = new CalcConstSlow();
    
    pthread_t thread0, thread1;
    cout << "Thread 1 starting ...";
    if(pthread_create(&thread0, NULL, calc, calc1)) {
        cout << "error creating thread" << endl;
        return -1;
    }
    cout << "[DONE]" << endl;
    
    cout << "Thread 2 starting ...";
    if(pthread_create(&thread1, NULL, calc, calc2)) {
        cout << "error creating thread" << endl;
        return -1;
    }
    cout << "[DONE]" << endl;
    
    if(pthread_join(thread0, NULL) || pthread_join(thread1, NULL))
    {
        cout << "error joinining" << endl;
        return -2;
    }
    
    // cout << "Complete." << endl;
    cout << calc1->result() << " * " << calc2->result() << " = " << calc1->result()*calc2->result() << endl;
    
    // cout << setprecision(12) << fixed;
    
    // double r1 = (*calc1)();
    // double r2 = (*calc2)();
    // 
    // cout << r1 << " * " << r2 << " = " << r1*r2 << endl;
    
    // cout << "\033[2J"; clear
    // cout << "\033[1;1H"; position cursor

	return 0;
}
