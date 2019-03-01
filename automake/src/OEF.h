#ifndef _OEF_H_
#define _OEF_H_

#include <string>

struct OEF {
    private:
        int type;
        float openingPrice;
        float avgChange;
        std::string name;
        std::string companyName;
    public:
        OEF(std::string n, std::string con, float opprice, float avgchg, int t);
        int get_type();
        float get_op_price();
        float get_avg_change();
        std::string get_name();
        std::string get_comp_name();
        void set_type(int new_type);
        void set_op_price(float new_price);
        void set_avg_change(float new_change);
        void set_name(std::string new_name);
        void set_comp_name(std::string new_comp_name);
        void setAvgChange(float fresh);

};

#endif