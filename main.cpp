#include <iostream>
#include "color.h"
#include "vec3.h"

void renderSampleImage(int imageWidth, int imageHeight) {
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int i=0; i<imageHeight; i++) {
        std::clog << "\rScanlines remaining: " << (imageHeight - i) << ' ' << std::flush;
        for (int j=0; j<imageHeight; j++) {
            auto r = double(j) / (imageWidth - 1);
            auto g = double(i) / (imageHeight - 1);
            auto b = 0.0;
            auto pixelColor = color(r, g, b);
            write_color(std::cout, pixelColor);
        }
    }
    std::clog << "\rDone.                          \n";

}


int main() {


    int imageWidth = 256;
    int imageHeight = 256;

    // Render
    renderSampleImage(imageWidth, imageHeight);
    // vec3 v(1, 2, 3);
    // std::cout << v << std::endl;

    

}