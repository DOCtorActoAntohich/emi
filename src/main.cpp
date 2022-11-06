#include <iostream>
#include <string>

#include <opencv2/core/cuda.hpp>
#include <opencv2/dnn.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>

#include "emi/exceptions.h"
#include "emi/windows/window.h"

std::string window_name = "Acceleration of SUGURI 2";

void run() {
    emi::window window(window_name);

    while (true) {
        auto frame = window.new_frame();

        cv::imshow("strem", frame);
        auto key = cv::waitKey(10);
        if (key == 'q') {
            break;
        }
    }
}

int main() {
    try {
        run();
    } catch (emi::window_not_found_exception& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}
