#include <iostream>

// IOCRProvider.h
class IOCRProvider {
public:
    // A pure virtual function that reads an image and returns the OCR output
    virtual std::string read(const std::string& imagePath) = 0;
    
    // A virtual destructor to ensure that deleting a pointer to an IOCRProvider deletes the correct object
    virtual ~IOCRProvider() {}
};