#include <string>
#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/core/cuda.hpp>

#include <windows.h>

#include "emi/windows/window.h"
#include "emi/exceptions.h"

std::string window_name = "Acceleration of SUGURI 2";

int main()
{
    try {
        emi::window window(window_name);
        std::cout << "handle is " << window.handle_ << std::endl;
    }
    catch (emi::window_not_found_exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
