#include <iostream>
#include "OEF.h"
#include <string>
#include <vector>
using namespace std;

bool checkGetPrice(OEF & oef, float price)
{
	if (oef.get_op_price() == price)  return true; else return false;
}

bool checkGetName(OEF & oef, std::string name)
{
	if (oef.get_name() == name) return true; return false;
}

bool checkGetCompany(OEF & oef, std::string compName)
{
	if (oef.get_comp_name() == compName) return true; else return false;
}

bool checkGetType(OEF & oef, int type)
{
	if (oef.get_type() == type)  return true; else return false;
}

bool checkGetAvg(OEF & oef, float avg)
{
	if (oef.get_avg_change() == avg)  return true; else return false;
}

int main() {
	string name = "name";
	string compname = "company";
	float price = 123;
	int type = 1;
    float avg = 15;
    OEF * oef = new OEF(name, compname, price, avg, type);
	vector<OEF> vec = {*oef};

	if (checkGetPrice(*oef, price)) cout << "Test \"CheckGetPrice\" passed.\n";
		else cout << "Test \"CheckGetPrice\" error.\n";

	if (checkGetName(*oef, name)) cout << "Test \"checkGetName\" passed.\n";
		else cout << "Test \"checkGetName\" error.\n";

	if (checkGetCompany(*oef, compname)) cout << "Test \"checkGetCompany\" passed.\n";
		else cout << "Test \"checkGetCompany\" error.\n";

	if (checkGetType(*oef, type)) cout << "Test \"checkGetType\" passed.\n";
		else cout << "Test \"checkGetType\" error.\n";

	if (checkGetAvg(*oef, avg)) cout << "Test \"checkGetAvg\" passed.\n";
		else cout << "Test \"checkGetAvg\" error.\n";

	return 0;
}