#include <iostream>
#include "mylib.h"

int main() {
    std::cout << "=== Test DLL mimalloc ===" << std::endl;

    int* p1 = allocateInt(42);
    int* p2 = allocateInt(100);

    std::cout << "[APP] p1=" << p1 << " p2=" << p2 << std::endl;

    freeInt(p1);
    freeInt(p2);

    int* arr = new int[5];
    for(int i=0;i<5;i++) arr[i] = i*10;
    std::cout << "[APP] Array at " << arr << ": ";
    for(int i=0;i<5;i++) std::cout << arr[i] << " ";
    std::cout << std::endl;
    delete[] arr;

    std::cout << "=== Finished ===" << std::endl;
    return 0;
}


// #include <Windows.h>
// #include <iostream>
//
// int main() {
//     HMODULE h = LoadLibraryA("MyDll.dll");
//     if (!h) {
//         DWORD err = GetLastError();
//         std::cout << "Failed to load MyDll.dll, error = " << err << std::endl;
//     } else {
//         std::cout << "Loaded MyDll.dll successfully!" << std::endl;
//         FreeLibrary(h);
//     }
//     return 0;
// }
