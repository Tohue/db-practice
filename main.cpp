#include <iostream>
#include <string.h>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (!strcmp(argv[1], "-h")) {
            std::cout << "OEF(Open-End Funds) Database\n" <<
                         "Made for second practice";
        return 0;
        }
    }
    
    

    return 0;
}