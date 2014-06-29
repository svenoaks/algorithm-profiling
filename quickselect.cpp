//
//  quickselect.cpp
//  algorithm
//
//  Created by Steve Myers on 6/29/14.
//  Copyright (c) 2014 ___SMP_PRODUCTIONS___. All rights reserved.
//

#include "quickselect.h"
#include <random>
#include <chrono>
#include <vector>
#include <deque>

quickselect::quickselect() : algortest::algorithm("quickselect") {};

static int partition(vector<int> &arr, int start, int end)
{
    int pivot_index = start + rand() % (end - start + 1);
    int pivot = arr[pivot_index];
    
    swap(arr[pivot_index], arr[end]);
    pivot_index = end;
    int i = start -1;
    
    for(int j = start; j <= end - 1; j++)
    {
        if(arr[j] >= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[pivot_index]);
    
    return i + 1;
}

static int quick_select(vector<int>& a, int left, int right, int n)
{
    if ( left == right )
        return a[left];
    int pivotIndex = partition(a, left, right);
    
    int length = pivotIndex - left + 1;
    if ( length == n)
        return a[pivotIndex];
    else if ( n < length )
        return quick_select(a, left, pivotIndex - 1, n);
    else
        return quick_select(a, pivotIndex + 1, right, n - length);
}

void quickselect::execute(va_list args)
{
    const int n = va_arg(args, int);
    const int m = va_arg(args, int);
    
    vector<int> numbers;
    vector<int> largest;
        
    auto ms = chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(1);
    
    default_random_engine generator(static_cast<default_random_engine::result_type>(ms));
    uniform_int_distribution<int> distribution(1, 100000);
    
    for (int i = n ; i ; --i)
    {
        numbers.push_back(distribution(generator));
    }
    
    srand(static_cast<unsigned int>(ms));
    
    int mth = quick_select(numbers, 0, n - 1, m);
    
    for (int i : numbers)
    {
        if (i >= mth)
        {
            largest.push_back(i);
        }
    }
    /*
    for (int i : largest)
    {
        cout << i << endl;
    }
     */
}


