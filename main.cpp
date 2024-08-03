#include <iostream>
#include "color.h"
#include "ray.h"
#include "vec3.h"

color rayColor(const ray& r) {
    return color(0, 0, 0);
}

void renderSampleImage(int imageWidth, int imageHeight) {

}


int main() {

    auto aspectRatio = 16.0 / 9.0;
    int imageWidth = 400;

    // Calculate the image height and ensure that it's at least 1
    int imageHeight = int(imageWidth / aspectRatio);
    imageHeight = (imageHeight < 1) ? 1 : imageHeight;


    // Camera
    auto focalLength = 1.0;
    auto viewportHeight = 2.0;
    auto viewportWidth = viewportHeight * (double(imageWidth)/imageHeight);
    auto cameraCenter = point3(0, 0, 0);

    // Calculate the vectors across the horizontal and down the vertical viewport edges
    auto viewportU = vec3(viewportWidth, 0, 0);
    auto viewportV = vec3(0, -viewportHeight, 0);

    // Calculator the horizontal and vertical delta vectors from pixel to pixel
    auto pixelDeltaU = viewportU / imageWidth;
    auto pixelDeltaV = viewportV / imageHeight;

    // Calculate the location of the upper left pixel
    auto viewportUpperLeft = cameraCenter - vec3(0, 0, focalLength) - viewportU/2 - viewportV/2;
    auto pixel00Loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);


    // Render
    std::cout << "P3\n" << imageWidth << ' ' << imageHeight << "\n255\n";

    for (int i=0; i<imageHeight; i++) {
        std::clog << "\rScanlines remaining: " << (imageHeight - i) << ' ' << std::flush;
        for (int j=0; j<imageHeight; j++) {
            auto pixelCenter = pixel00Loc + (j * pixelDeltaU) + (i * pixelDeltaV);
            auto rayDirection = pixelCenter - cameraCenter;
            ray r(cameraCenter, rayDirection);
            color pixelColor = rayColor(r);
            write_color(std::cout, pixelColor);
        }
    }
    std::clog << "\rDone.                          \n";
    

}