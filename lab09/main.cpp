#include "map.h"
#include <cstdio>

int main()
{
    Map<int, const char *> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m.Clear();
    for (auto[key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m.Set(69, "alex");
    printf("%s", m[69]);
    const char* ret;
    printf("yes?%d", m.Get(69, ret));
    if (ret)    printf("%s", ret);
    printf("%s", m[70]);
    printf("\n\n%d", m.Count());
    m.Delete(69);
    printf("\n\n%d", m.Count());
    printf("%s", m[69]);

    printf("\n\n%d", m.Count());
    return 0;
}
