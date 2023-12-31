// TesseractOCRProviderTests.cpp

#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "TesseractOCRProvider.h"
#include <iostream>

TEST_CASE("TesseractOCRProvider read method test", "[TesseractOCRProvider]") {
    TesseractOCRProvider ocrProvider;

    std::string imagePath = "./tesseract-test-image.png";
    std::string expectedText = R"(Running Tesseract
Tesseract is a command-line program, so first open a terminal or command prompt. The command is
used like this:
tesseract imagename outputbase [-1 lang] [-psm pagesegmode] [configfile...]
So basic usage to do OCR on an image called ‘myscan.png’ and save the result to ‘out.txt' would be:
tesseract myscan.png out
Or to do the same with German:
)";
    
    std::string result = ocrProvider.read(imagePath);
    std::cout << result << std::endl;
    REQUIRE(result == expectedText);
}
