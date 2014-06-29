//
//  keepSorted.h
//  algorithm
//
//  Created by Steve Myers on 6/29/14.
//  Copyright (c) 2014 ___SMP_PRODUCTIONS___. All rights reserved.
//

#ifndef __algorithm__keepSorted__
#define __algorithm__keepSorted__

#include <iostream>
#include <cstdarg>

#include "algorithm.h"

class keepSorted : public algortest::algorithm
{
protected:
    void execute(va_list);
    
public:
    keepSorted();
    
};


#endif /* defined(__algorithm__keepSorted__) */
