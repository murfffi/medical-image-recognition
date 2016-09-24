#include "hough_circles.h"
#include <math.h>
#include <algorithm>

namespace img_recog {
	using namespace cimg_library;

	namespace {
		const float STEP = 1;
	}
	void HoughCircles::filter(CImgBmp& image) const {
		float backColor = 0;
		CImg<float> trans(image.dimx(), image.dimy(), 1, 1, backColor);
		cimg_forXY(image, x, y) {
			if (image(x, y)) {
				int leftX = std::max(0, x - radius);
				int rightX = std::min(image.dimx(), x + radius);
				for (int cx = leftX; cx <= rightX; ++cx) {
					double offsetY = std::sqrt((double)(radius * radius - (cx - x) * (cx - x)));
					int cy = static_cast<int>(y + offsetY);
					if (cy < image.dimy())
						trans(cx, cy) += STEP;
					cy = static_cast<int>(y - offsetY);
					if (cy >= 0)
						trans(cx, cy) += STEP;
				}
			}
		}
		image.assign(trans.normalize(0, 255));
	}
}
