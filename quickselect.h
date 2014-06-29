//
//  quickselect.h
//  algorithm
//
//  Created by Steve Myers on 6/29/14.
//  Copyright (c) 2014 ___SMP_PRODUCTIONS___. All rights reserved.
//

#ifndef __algorithm__quickselect__
#define __algorithm__quickselect__

#include <iostream>

#include <cstdarg>

#include "algorithm.h"

class quickselect : public algortest::algorithm
{
protected:
    void execute(va_list);
    
public:
    quickselect();
    
};


#endif /* defined(__algorithm__quickselect__) */
