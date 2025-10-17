//
// Created by wnc on 2025/10/17.
//

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "mimalloc.h"

int main() {

    // mi_version();

    printf("=== mimalloc dynamic link demo ===\n");

    // 测试 malloc/free 是否正常工作
    char* msg = (char*)malloc(64);
    strcpy(msg, "Hello from mimalloc (DLL)");
    printf("msg = %s\n", msg);

    int* arr = (int*)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) arr[i] = i * 2;

    printf("arr: ");
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    printf("\n");

    free(msg);
    free(arr);

    // 验证分配来源（可选）
    void* p = malloc(128);
    int* arr2 = new int[128];
    printf("ptr = %p, from mimalloc? %s\n",
           arr2, mi_is_in_heap_region(p) ? "yes" : "no");
    free(p);

    printf("=== done ===\n");
    return 0;
}
