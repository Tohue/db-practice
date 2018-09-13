#ifndef _BASE_H_
#define _BASE_H_

#include <vector>

#include "OEF.h"

class Base {
    private:
        std::vector<OEF> fundList; 
    public:
        int add();
        OEF * find();
        ~Base();
};


#endif