set(OCRASSISTANTLIB_SOURCEFILES
        include/OCRReader.h
        src/OCRReader.cpp)

add_library(OCRASSISTANTLIB ${OCRASSISTANTLIB_SOURCEFILES})

target_include_directories(OCRASSISTANTLIB
    PUBLIC
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${Tesseract_INCLUDE_DIRS}
        ${Catch2_INCLUDE_DIRS}
)

# tesseract link library Tesseract::libtesseract produced by install instructions manifests install
target_link_libraries(OCRASSISTANTLIB Tesseract::libtesseract leptonica Catch2::Catch2 Catch2::Catch2WithMain)
add_subdirectory(test)