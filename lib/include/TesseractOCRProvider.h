// TesseractOCRProvider.h
#include "IOCRProvider.h"
#include "OCRReader.h"

class TesseractOCRProvider : public IOCRProvider {
public:
    TesseractOCRProvider() : ocrReader(std::make_unique<OCRReader>()) {}
    
    std::string read(const std::string& imagePath) override {
        return ocrReader->read(imagePath);
    }
    
private:
    std::unique_ptr<OCRReader> ocrReader;
};
