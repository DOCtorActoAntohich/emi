#include "window.h"

#include "emi/exceptions.h"

using namespace emi;


namespace {
HWND find_window_(std::string name) {
    HWND window_handle = FindWindow(NULL, name.data());
    if (window_handle == NULL) {
        throw window_not_found_exception{name};
    }
    return window_handle;
}
}

window::window(std::string name) : name_(name) {
    handle_ = find_window_(name);
}
