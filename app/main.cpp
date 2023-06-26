#include "TesseractOCRProvider.h"
#include <iostream>

int main(int argc, char** argv) {
    if(argc != 2) {
        std::cout << "Usage: " << argv[0] << " <image_path>\n";
        return 1;
    }

    std::string imagePath = argv[1];

    try {
        TesseractOCRProvider ocrProvider;
        std::string result = ocrProvider.read(imagePath);
        std::cout << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
