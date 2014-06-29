//
//  algorithm.cpp
//  algorithm
//
//  Created by Steve Myers on 6/28/14.
//  Copyright (c) 2014 ___SMP_PRODUCTIONS___. All rights reserved.
//

#include "algorithm.h"

using namespace std;

namespace algortest
{
    algorithm::algorithm(string name) : name(name) {};
    
    
    algorithm::time_type algorithm::result()
    {
        return res;
    }
    
    void algorithm::printResult()
    {
        cout << "The algorithm " << name << " took " << result() << " " << currentMeasurement << " to run." << endl;
    }
    
    template<>
    void algorithm::setMeasurementString<chrono::milliseconds>()
    {
        currentMeasurement = "milliseconds";
    }
    
    template<>
    void algorithm::setMeasurementString<chrono::seconds>()
    {
        currentMeasurement = "seconds";
    }
    
    template<>
    void algorithm::setMeasurementString<chrono::nanoseconds>()
    {
        currentMeasurement = "nanoseconds";
    }
    
    template<>
    void algorithm::setMeasurementString<chrono::microseconds>()
    {
        currentMeasurement = "microseconds";
    }
    
    template<>
    void algorithm::setMeasurementString<chrono::minutes>()
    {
        currentMeasurement = "minutes";
    }

}