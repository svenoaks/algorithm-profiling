//
//  sortThem.cpp
//  algorithm
//
//  Created by Steve Myers on 6/29/14.
//  Copyright (c) 2014 ___SMP_PRODUCTIONS___. All rights reserved.
//

#include "sortThem.h"

#include <random>
#include <chrono>
#include <vector>
#include <deque>
#include <algorithm>

sortThem::sortThem() : algortest::algorithm("sortThem") {};

void sortThem::execute(va_list args)
{
    const int n = va_arg(args, int);
    const int m = va_arg(args, int);
    
    deque<int> numbers;
    vector<int> largest;
    make_heap(numbers.begin(), numbers.end(), std::greater<int>());
    
    auto ms = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
    
    default_random_engine generator(static_cast<default_random_engine::result_type>(ms));
    uniform_int_distribution<int> distribution(1, 100000);
    
    for (int i = n ; i ; --i)
    {
        numbers.push_back(distribution(generator));
    }
    
    sort(numbers.begin(), numbers.end(), std::greater<int>());
    
    for (int i = m ; i ; --i)
    {
        largest.push_back(numbers.front());
        numbers.pop_front();
    }
    /*
    for (auto i : largest)
    {
        cout << i << endl;
    }
     */
    
}