//
//  algorithm.h
//  algorithm
//
//  Created by Steve Myers on 6/28/14.
//  Copyright (c) 2014 ___SMP_PRODUCTIONS___. All rights reserved.
//

#ifndef __algorithm__algorithm__
#define __algorithm__algorithm__

#include <iostream>
#include <string>
#include <chrono>
#include <utility>
#include <cstdarg>

using namespace std;


namespace algortest
{
    class algorithm
    {
        typedef uint64_t time_type;
    private:
        string currentMeasurement;
        
        template<typename TimeT>
        void setMeasurementString();
    
    protected:
        std::string name;
        time_type res;
        
        algorithm(std::string name);
        virtual void execute(va_list)=0;
       
    public:
        template <typename TimeT>
        void beginTest(int, ...);
        
        time_type result();
        void printResult();
    };
    
    template<typename TimeT>
    void algorithm::setMeasurementString()
    {
        currentMeasurement = "unsupported";
    }
    
    //int n - number of arguments to the variadic function
    template <typename TimeT>
    void algorithm::beginTest(int n, ...)
    {
        va_list args;
        va_start(args, n);
        auto start = chrono::high_resolution_clock::now();
        
        execute(args);
        
        auto duration = chrono::duration_cast<TimeT>
                    (chrono::high_resolution_clock::now() - start);
        
        setMeasurementString<TimeT>();
        
        res = duration.count();
        va_end(args);
    }
}

#endif /* defined(__algorithm__algorithm__) */
