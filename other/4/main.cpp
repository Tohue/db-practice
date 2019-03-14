#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
void run(vector<int> list) {
int sum;
for(int i = 0; i < list.size(); i++) {
    if(list[i]>=0) {
        cout<<list[i]<<" "<< (int)pow(list[i], 3) << " ";
        sum+=list[i];
        list.insert(list.begin() + (++i), (int)pow(list[i], 3));
    }
    else {
        list.erase(list.begin() + i);
        i--;
    }
}
cout << "sum: " << sum<<endl;
}
int main() {
vector<int> n1{2,5,8,11,14,4,7,12,1, 6};
vector<int> n2{10,1,-8,2,2,2,-50,-9,1,1};
vector<int> n3{2,5,-8,-11,14,-4,7,-12,1, 6};
vector<int> n4{8,-15,80,110,-1,-4,-7,1,2,3};
run(n1);
run(n2);
run(n3);
run(n4);
return 0;
}