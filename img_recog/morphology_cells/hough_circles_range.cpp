#include "hough_circles_range.h"
#include "hough_circles.h"
#include "simple_binarizer.h"
#include <cassert>

namespace img_recog {
	namespace {
		const double DEFAULT_DEVIATION_PERCENT = 5;

		int getDeviation(int radius, double percentDev) {			
			return static_cast<int>(radius * percentDev / 100) + 1;
		}
	}

	HoughCirclesRange::HoughCirclesRange(int radius) 
		: radiusMin(radius - getDeviation(radius, DEFAULT_DEVIATION_PERCENT)),
		radiusMax(radius + getDeviation(radius, DEFAULT_DEVIATION_PERCENT))
	{
		assert(radiusMin > 0);
		assert(radiusMax >= radiusMin);
	}		
		
	void HoughCirclesRange::filter(CImgBmp& image) const {
		cimg_library::CImg<int> houghAll(image.dimx(), image.dimy(), 1, 1, 0);
		for (int hr = radiusMin; hr <= radiusMax; ++hr) {
			CImgBmp forHough(image, false);
			forHough << HoughCircles(hr) << SimpleBinarizer(160);
#ifndef NDEBUG 
			cimg_library::CImgStats stats(forHough);
			assert(stats.min == 0);
			assert(stats.max == 0xFF);
#endif NDEBUG
			houghAll += forHough;
		}
		houghAll.cut(0, 255);
		cimg_library::CImgStats stats(houghAll);
		assert(stats.min == 0);
		assert(stats.max == 0xFF);
		image.assign(houghAll);
	}
}
