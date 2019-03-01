#include "OEF.h"


OEF::OEF(std::string n, std::string con, float opprice, float avgchg, int t) :
    name(n), 
    companyName(con),
    openingPrice(opprice),
    avgChange(avgchg),
    type(t){

}

std::string OEF::get_name() {
    return name;
}
std::string OEF::get_comp_name() {
    return companyName;
}
float OEF::get_op_price() {
    return openingPrice;
}
float OEF::get_avg_change(){
    return avgChange;
}
int OEF::get_type() {
    return type;
}
