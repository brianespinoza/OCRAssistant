#include "OCRReader.h"
#include "leptonica/allheaders.h"

OCRReader::OCRReader() {
    api = std::make_unique<tesseract::TessBaseAPI>();
    if (api->Init(NULL, "eng")) {
        fprintf(stderr, "Could not initialize tesseract.\n");
        exit(1);
    }
}

OCRReader::~OCRReader() {

}

std::string OCRReader::read(const std::string& imagePath) {
    Pix *image = pixRead(imagePath.c_str());
    api->SetImage(image);
    char* outText = api->GetUTF8Text();
    std::string result(outText);
    // Don't call `api->End()` here because that will prematurely end the
    // `TessBaseAPI` instance and you won't be able to use it again.
    delete [] outText;
    pixDestroy(&image);
    
    return result;
}
