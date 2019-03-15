#include <iostream>
using namespace std;

extern "C" int testf(int a, int b, int d);

int main()
{
        int x,y,z;
        cin >> x >> y >> z;
        cout << (x+2*y+3*z)/4 << " " << testf(x,y,z) << endl;
        return 0;
}
   