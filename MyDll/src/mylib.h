#pragma once

#ifdef _WIN32
  #ifdef MYDLL_EXPORTS
    #define MYDLL_API __declspec(dllexport)
  #else
    #define MYDLL_API __declspec(dllimport)
  #endif
#else
  #define MYDLL_API
#endif

extern "C" {
    MYDLL_API int* allocateInt(int value);
    MYDLL_API void freeInt(int* p);
}
