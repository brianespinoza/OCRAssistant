#ifndef OCRREADER_H
#define OCRREADER_H

#include <string>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

class OCRReader {
public:
    OCRReader();
    ~OCRReader();

    std::string read(const std::string& imagePath);

private:
    std::unique_ptr<tesseract::TessBaseAPI> api;
};

#endif // OCRREADER_H