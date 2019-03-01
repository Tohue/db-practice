#ifndef _BASE_H_
#define _BASE_H_

#include <vector>

#include "OEF.h"

class Base {
    private:
        std::vector<OEF> fundList; 
    public:
        int add(std::string st_name, std::string compname, float price, float avgchg, int oeftype);
        std::vector<OEF> getList();
        OEF * find();
        int remove_by_num(int num);
        int remove_by_name(std::string str);
        int remove_by_company(std::string comp);
        ~Base();
};


#endif