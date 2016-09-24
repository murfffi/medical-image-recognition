#include "grayscale_filter.h"

namespace img_recog {

	void GrayscaleFilter::filter(CImgBmp& image) const {
		int sum = 0;
		double norm_distance;
		double norm_q = std::sqrt((double)image.dimv());
		int channelVal = 0;
		cimg_forXY(image, x, y)
		{
			sum = 0;
			cimg_forV(image, v) {
				channelVal = image(x, y, v);
				sum += channelVal * channelVal;
			}
			norm_distance = std::sqrt((double)sum) / norm_q;
			CImgBmp::value_type graycolor = static_cast<CImgBmp::value_type>(floor(norm_distance));
			cimg_forV(image, v)
				image(x, y, v) = graycolor;
		}
	}
}
