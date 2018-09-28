#include "base.h"

int Base::add(std::string st_name, std::string compname, float price, float avgchg, int oeftype) {
    OEF * oef = new OEF(st_name, compname, price, avgchg, oeftype);
    fundList.push_back(*oef);
}

std::vector<OEF> Base::getList() {
    return fundList;
}