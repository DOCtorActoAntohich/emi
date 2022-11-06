#pragma once

#include <exception>
#include <format>

namespace emi {
    class window_not_found_exception : std::exception {
    public:
        window_not_found_exception(std::string window_name) {
            text_ = std::format("Window not found: {}", window_name);
        }

        const char* what() const noexcept override {
            return text_.data();
        }

    private:
        std::string text_;
    };
}
