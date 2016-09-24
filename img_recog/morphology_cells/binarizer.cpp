#include "binarizer.h"
#include <iostream>

namespace img_recog {
	void Binarizer::filter(img_recog::CImgBmp &image) const {
		double threshold = getThresholdFor(image);
		int pixelsWhite =0, pixelsBlack =0, totalPixels = image.dimx() * image.dimy();
		cimg_forV (image, v) {
			cimg_forXY (image, x, y) {
				if (image(x, y, v) < threshold) {
					++pixelsBlack;
					image(x, y, v) = 0;
				}
				else {
					++pixelsWhite;
					image(x, y, v) = 0xFF; 
				}
			}
		}
		std::cout << (double)pixelsBlack / totalPixels * 100 << "% pixels black.\n";
		std::cout << (double)pixelsWhite / totalPixels * 100 << "% pixels white.\n";
	}
}
