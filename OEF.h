#ifndef _OEF_H_
#define _OEF_H_

#include <string>

enum typeOEF {interval, open, close};

struct OEF {
    private:
        typeOEF type;
        float openingPrice;
        float avgChange;
        std::string name;
        std::string companyName;
    public:
        OEF();
        void setAvgChange(float fresh);

};

#endif