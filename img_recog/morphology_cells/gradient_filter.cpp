#include "gradient_filter.h"

namespace img_recog {

	void GradientFilter::filter(CImgBmp& image) const {
		cimg_library::CImgList<> list = image.get_gradientXY(4);
		assert(list.size == 2);
		cimglist_for(list, i)
			list[0].max(list[i]);
		image = list[0];
	}
}
