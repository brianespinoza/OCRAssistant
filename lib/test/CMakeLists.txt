# Locate the Catch2 package
find_package(Catch2 REQUIRED)

# Declare your test executable
add_executable(TesseractOCRProviderTests TesseractOCRProviderTests.cpp)

# Link your library to your test executable
target_link_libraries(TesseractOCRProviderTests PRIVATE OCRASSISTANTLIB)

# Link the Catch2 testing library to your test executable
target_link_libraries(TesseractOCRProviderTests PRIVATE Catch2::Catch2)

add_custom_command(TARGET TesseractOCRProviderTests POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy
                       ${CMAKE_SOURCE_DIR}/lib/test/tesseract-test-image.png
                       ${CMAKE_CURRENT_BINARY_DIR}/tesseract-test-image.png)