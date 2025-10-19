#include "mylib.h"

#include "mimalloc-new-delete.h"
#include "mimalloc.h"
#include <iostream>

int* allocateInt(int value) {
    int* p = new int(value);
    std::cout << "[DLL] Allocated int at " << p << " value=" << *p << std::endl;

    return p;
}

void freeInt(int* p) {
    std::cout << "[DLL] Free int at " << p << std::endl;
    delete p;
}
