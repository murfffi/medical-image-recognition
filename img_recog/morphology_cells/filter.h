#ifndef FILTER_H
#define FILTER_H

#include "cimg_bmp.h"

namespace img_recog {
	class Filter {
	public:
		virtual void filter(CImgBmp& image) const =0;
	};

	inline CImgBmp& operator<<(CImgBmp& image, Filter& filter) {
		filter.filter(image);
		return image;
	}
}

#endif //FILTER_H
