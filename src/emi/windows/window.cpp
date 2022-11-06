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

const cv::Mat& window::new_frame() {
    HDC window_device_context = GetDC(handle_);
    HDC compatible_device_context = CreateCompatibleDC(window_device_context);

    RECT window_rect;
    GetClientRect(handle_, &window_rect);

    auto width = window_rect.right;
    auto height = window_rect.bottom;

    if (last_frame_.size[0] != width || last_frame_.size[1] != height) {
        last_frame_.create(height, width, CV_8UC4);
    }

    HBITMAP captured_data =
        CreateCompatibleBitmap(window_device_context, width, height);
    BITMAPINFOHEADER bitmap_info{
        .biSize = sizeof(BITMAPINFOHEADER),
        .biWidth = width,
        .biHeight = -height,  // Flips upside down for correct rendering.
        .biPlanes = 1,
        .biBitCount = 32,
        .biCompression = BI_RGB,
        .biSizeImage = 0,
        .biXPelsPerMeter = 0,
        .biYPelsPerMeter = 0,
        .biClrUsed = 0,
        .biClrImportant = 0,
    };

    SelectObject(compatible_device_context, captured_data);
    BitBlt(
        compatible_device_context,
        0,
        0,
        width,
        height,
        window_device_context,
        0,
        0,
        SRCCOPY);
    GetDIBits(
        compatible_device_context,
        captured_data,
        0,
        height,
        last_frame_.data,
        reinterpret_cast<BITMAPINFO*>(&bitmap_info),
        DIB_RGB_COLORS);

    DeleteObject(captured_data);
    DeleteDC(compatible_device_context);
    ReleaseDC(handle_, window_device_context);

    return last_frame_;
}
