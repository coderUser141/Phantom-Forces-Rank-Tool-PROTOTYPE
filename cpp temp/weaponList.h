#pragma once
#include <string>

typedef struct _Wl {

    std::wstring category;
    std::wstring name;
    int rank;
    inline _Wl(std::wstring, int);

} weaponList, WL;