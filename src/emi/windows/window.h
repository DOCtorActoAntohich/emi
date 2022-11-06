#pragma once

#include <string>
#include <windows.h>

#include <opencv2/opencv.hpp>

namespace emi {
    class window {
    public:
        window(std::string name);

        const cv::Mat& new_frame();

    private:
        std::string name_;
        HWND handle_;
        cv::Mat last_frame_;
    };
}
