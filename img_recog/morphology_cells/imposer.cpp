#include "imposer.h"
#include <algorithm>

namespace img_recog {
	void Imposer::filter(img_recog::CImgBmp &image) const {
		int maxX = std::min(image.dimx(), imageToImpose.dimx());
		int maxY = std::min(image.dimy(), imageToImpose.dimy());
		for	(int x = 0; x < maxX; ++x)
			for (int y = 0; y < maxY; ++y) {
				CImgBmp::value_type val = imageToImpose(x, y);
				if (val > 0) {
					cimg_forV(image, v) {
						image(x, y, v) = v == layerToSubs ? val : 0; 
					}
				}
			}
	}
}
