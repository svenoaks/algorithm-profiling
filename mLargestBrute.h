//
//  mLargest.h
//  algorithm
//
//  Created by Steve Myers on 6/28/14.
//  Copyright (c) 2014 ___SMP_PRODUCTIONS___. All rights reserved.
//

#ifndef __algorithm__mLargest__
#define __algorithm__mLargest__

#include <iostream>
#include <cstdarg>

#include "algorithm.h"

class mLargestBrute : public algortest::algorithm
{
protected:
    void execute(va_list);
    
public:
    mLargestBrute();
    
};

#endif /* defined(__algorithm__mLargest__) */
