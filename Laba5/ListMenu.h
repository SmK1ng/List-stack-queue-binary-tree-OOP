#pragma once

#include "Menu.h"
#include "DLL.h"

class ListMenu final : public Menu
{
    DLL list;

public:
    ListMenu();

    void processMenuItem(int number) override;
};

