# OCR Assistant

OCR Assistant is a command-line program that utilizes the Tesseract Optical Character Recognition (OCR) Engine to read and recognize text from an image file.

## Prerequisites

To build and run OCR Assistant, you need the following tools:

- CMake (version 3.15 or later)
- A C++ compiler supporting C++17
- vcpkg package manager

Additionally, the project depends on these libraries:

- Tesseract
- Leptonica

## Building the Project

1. First, ensure that the Tesseract and Leptonica libraries are installed on your system. If you're using the vcpkg package manager, you can install these libraries with the following commands:

    ```bash
    vcpkg install tesseract
    vcpkg install leptonica
    ```

2. Set the CMake toolchain file to the vcpkg.cmake provided by vcpkg. This can be done by setting the `CMAKE_TOOLCHAIN_FILE` variable in the main `CMakeLists.txt` file:

    ```cmake
    set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "Vcpkg toolchain file")
    ```

3. Build the project using CMake:

    ```bash
    mkdir build
    cd build
    cmake ..
    make
    ```

## Running Tests

Tests are written using the Catch2 testing framework. To run the tests:

```bash
cd build/test
./OCRReaderTests
```

## Configuration

To specify the path to the Tesseract `tessdata` directory, set TESSDATA_PREFIX path as an environment variable:

```bash
    export TESSDATA_PREFIX=/path/to/tessdata/parent/directory
```

Replace `/path/to/tessdata/parent/directory` with the actual path to the parent directory of your `tessdata` folder.

Tesseract language test data can be found: https://github.com/tesseract-ocr/tessdata/blob/main/ 

Download eng.traineddata for English.

## Usage

After building the project, you can use the OCR Assistant as follows:

```bash
cd app
./OCRAssistant ../lib/test/tesseract-test-image.png
```

Replace `/path/to/image/file` with the path to the image file you want to process. The program will print the recognized text to the console.

## Disclaimer

Please note that the accuracy of the text recognition depends on the quality and clarity of the input image.