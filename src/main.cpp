#include <iostream>
#include <vector>
#include "interact.h"

int main() {
    Interact * interact = new Interact();
    return interact->init();
}