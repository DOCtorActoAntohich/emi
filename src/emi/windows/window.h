#pragma once

#include <string>
#include <windows.h>

namespace emi
{
    class window
    {
    public:
        window(std::string name);
        std::string name_;
        HWND handle_;
    private:
    };
}
