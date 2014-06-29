//
//  mLargest.cpp
//  algorithm
//
//  Created by Steve Myers on 6/28/14.
//  Copyright (c) 2014 ___SMP_PRODUCTIONS___. All rights reserved.
//

#include "mLargestBrute.h"
#include "algorithm.h"
#include <list>
#include <vector>
#include <cstdarg>
#include <chrono>
#include <random>

using namespace std;

mLargestBrute::mLargestBrute() : algortest::algorithm("mLargestBrute") {};

void mLargestBrute::execute(va_list args)
{
    const int n = va_arg(args, int);
    const int m = va_arg(args, int);
    //Used linked list std::list for O(1) removal of items.
    list<int> numbers;
    vector<int> largest;
    
    // Fill the list of numbers with n random numbers between 1 and 100,000.
    
    auto ms = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
    
    default_random_engine generator(static_cast<default_random_engine::result_type>(ms));
    uniform_int_distribution<int> distribution(1, 100000);
    
    for (int i = n ; i ; --i)
    {
        numbers.push_back(distribution(generator));
    }
    
    /* This is the dominant time complexity feature of the algorithm. We have a nested loop.
     * We can see that the outer loop repeats m times, the first time the inner loops has n iterations,
     * the second, n - 1 iterations (we removed an element) all the way to n - (m - 1) iterations
     * in the final iteration of the outer loop.
     *
     * Removing the constants, we see that the algorithm is O(nm) and also
     * can not perform worse than O(n^2).
     */
    for (int i = m ; i ; --i)
    {
        auto largestIt = numbers.begin();
        
        for (auto it = numbers.begin(); it != numbers.end(); ++it)
        {
            if (*it > *largestIt)
            {
                largestIt = it;
            }
        }
        largest.push_back(*largestIt);
        numbers.erase(largestIt);
    }
    /*
     for (auto i : largest)
     {
     cout << i << endl;
     }
     */
}

