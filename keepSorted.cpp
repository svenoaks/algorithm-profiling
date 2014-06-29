//
//  keepSorted.cpp
//  algorithm
//
//  Created by Steve Myers on 6/29/14.
//  Copyright (c) 2014 ___SMP_PRODUCTIONS___. All rights reserved.
//

#include "keepSorted.h"
#include <random>
#include <chrono>
#include <vector>
#include <functional>

keepSorted::keepSorted() : algortest::algorithm("keepSorted") {};

void keepSorted::execute(va_list args)
{
    const int n = va_arg(args, int);
    const int m = va_arg(args, int);
    
    vector<int> numbers;
    vector<int> largest;
    make_heap(numbers.begin(), numbers.end());
    
    auto ms = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
    
    default_random_engine generator(static_cast<default_random_engine::result_type>(ms));
    uniform_int_distribution<int> distribution(1, 100000);
    
    for (int i = n ; i ; --i)
    {
        numbers.push_back(distribution(generator));
        push_heap(numbers.begin(), numbers.end());
    }
    
    for (int i = m ; i ; --i)
    {
        largest.push_back(numbers.front());
        pop_heap(numbers.begin(), numbers.end());
        numbers.pop_back();
    }
    /*
    for (auto i : largest)
    {
        cout << i << endl;
    }
    */

}