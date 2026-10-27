#include <iostream>
#include <iomanip>
using namespace std;

class Compressor {
public:
    virtual ~Compressor() {}
    virtual double compress(double fileSize) const { return fileSize; }
};

class TextCompressor : public Compressor {
public:
    double compress(double fileSize) const override { return 0.40 * fileSize; }
};

class ImageCompressor : public Compressor {
public:
    double compress(double fileSize) const override { return 0.70 * fileSize; }
};

int main() {
    double size;
    cout << "Enter original file size (MB): ";
    cin >> size;
    if (!cin || size < 0) {
        cout << "Invalid input.\n";
        return 1;
    }

    TextCompressor tc;
    ImageCompressor ic;
    Compressor* c1 = &tc;
    Compressor* c2 = &ic;

    cout << fixed << setprecision(2);
    cout << "\nText file  - Original: " << size << " MB, Compressed: " << c1->compress(size) << " MB\n";
    cout << "Image file - Original: " << size << " MB, Compressed: " << c2->compress(size) << " MB\n";
    return 0;
}
