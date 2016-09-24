#include "opening.h"
#include <cassert>

namespace img_recog {
	void Opening::filter(CImgBmp& image) const {
		CImgBmp structElem(createStructElem());
		assert(structElem.dimv() == 1);
		image.erode(structElem);
		image.dilate(structElem);
	}

	CImgBmp Opening::createStructElem() const {
		unsigned char backColor = 0, foreColor = 0xFF;
		CImgBmp structElem(structCircleDiameter, structCircleDiameter, 1, 1, backColor);
		assert(structElem.dimv() == 1);
		structElem.draw_circle(structCircleDiameter / 2, structCircleDiameter / 2, structCircleDiameter / 2.0F, &foreColor);
		return structElem;
	}
}
