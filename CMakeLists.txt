cmake_minimum_required(VERSION 3.0)
# Add the path to the vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake CACHE STRING "")


project(OCRAssistant)

set(Tesseract_DIR "../vcpkg/installed/arm64-osx/share/tesseract")
set(Leptonica_DIR "../vcpkg/installed/arm64-osx/share/leptonica")
set(LibArchive_INCLUDE_DIR "../vcpkg/installed/arm64-osx/share/libarchive")

# Find the Tesseract and Leptonica packages
find_package(Tesseract CONFIG REQUIRED)
find_package(Leptonica CONFIG REQUIRED)


add_executable(OCRAssistant src/main.cpp)

# Link Tesseract and Leptonica to your executable
target_link_libraries(OCRAssistant PRIVATE Tesseract::libtesseract leptonica)
