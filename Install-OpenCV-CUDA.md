# How to build and install OpenCV with CUDA

> [Video by some cool dude](https://youtu.be/-GY2gT2umpk)

I am gonna focus on CMake GUI because I suck. ![:ohh_yeah:](https://steamcommunity-a.akamaihd.net/economy/emoticon/:ohh_yeah:)

Install Visual Studio 2019. You need **exactly this version** for C++ compiler, or else it won't work.

Install NVidia CUDA and cuDNN.

Download [opencv](https://github.com/opencv/opencv/tree/4.5.2) and [opencv_contrib](https://github.com/opencv/opencv_contrib/tree/4.5.2) as ZIP.
Extract them next to each other in some random folder.

In CMake specify the `opencv` folder and some `build` folder for intermediates, then generate configuration.

After that, specify these options:

- `WITH_CUDA` = `true`
- `OPENCV_DNN_CUDA` = `true`
- `BUILD_opencv_dnn` = `true`
- `BUILD_opencv_world` = `true`
- `OPENCV_EXTRA_MODULES_PATH` = `*/opencv_contrib-4.5.2/modules`
- `ENABLE_FAST_MATH` = `true`

Configure again, then specify these:

- `CUDA_ARCH_PTX` = empty value.
- `CUDA_FAST_MATH` = `true`
- `CMAKE_CONFIGURATION_TYPES` = `Release` but you might want to leave `Debug`.
- `CUDA_ARCH_BIN` = `<version>` (see below)

Regarding `CUDA_ARCH_BIN`, go [here](https://en.wikipedia.org/wiki/CUDA#GPUs_supported), find your GPU by name, then use the number from `Compute capability (version)` column as the only value.
More values means support for more hardware, but also more time to build.
You will probably need only one version because I doubt you have more than one GPU. ![:ohh_yeah:](https://steamcommunity-a.akamaihd.net/economy/emoticon/:ohh_yeah:)

Configure it for the last time, then generate binaries.

After generating, execute:

`cmake --build <path/to/build> --target INSTALL --config Release`

After a long wait, go to `build/install` and use OpenCV (with CUDA!!) freely. I put it into `lib/opencv`.
