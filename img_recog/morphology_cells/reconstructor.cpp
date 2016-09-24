#include "reconstructor.h"
#include <cassert>

namespace img_recog {

	void Reconstructor::filter(CImgBmp& image) const {
		image.min(original);
		CImgBmp last;
		while (last != image) {
			assert(last.dimv() == 0 || last.get_min(image) == last);
			last.assign(image, false);
			assert(last == image);
			image.dilate(3);
			image.min(original);		
		}		
	}
}
