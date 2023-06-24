#ifndef OCRASSISTANT_H
#define OCRASSISTANT_H

#include <string>
#include "tesseract/baseapi.h"
#include "leptonica/allheaders.h"

class OCRAssistant {
public:
    OCRAssistant();
    ~OCRAssistant();

    std::string processImage(const std::string& imagePath);

private:
    tesseract::TessBaseAPI* api;
};

#endif // OCRAssistant_H
