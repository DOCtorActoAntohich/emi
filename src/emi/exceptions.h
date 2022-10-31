#pragma once

#include <exception>
#include <format>

namespace emi {
    class window_not_found_exception : std::exception {
    public:
        window_not_found_exception(std::string window_name) : name_(window_name) {}

        const char* what() const noexcept override {
            return std::format("Window not found: {}", name_).data();
        }
    private:
        std::string name_;
    };
}
