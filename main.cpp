//
//  main.cpp
//  algorithm
//
//  Created by Steve Myers on 6/28/14.
//  Copyright (c) 2014 ___SMP_PRODUCTIONS___. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <memory>

#include "algorithm.h"
#include "mLargestBrute.h"
#include "keepSorted.h"
#include "sortThem.h"
#include "quickselect.h"

using namespace std;
using namespace algortest;

int main()
{
    const int n = 100000;
    const int m = 10000;
    const int numArguments = 2;
    
    unique_ptr<algorithm> brutus{new mLargestBrute};
    unique_ptr<algorithm> sorted{new keepSorted};
    unique_ptr<algorithm> sort{new sortThem};
    unique_ptr<algorithm> qselect{new quickselect};
    
    brutus->beginTest<chrono::milliseconds>(numArguments, n, m);
    sorted->beginTest<chrono::milliseconds>(numArguments, n, m);
    sort->beginTest<chrono::milliseconds>(numArguments, n, m);
    qselect->beginTest<chrono::milliseconds>(numArguments, n, m);
    
    brutus->printResult();
    sorted->printResult();
    sort->printResult();
    qselect->printResult();
}

