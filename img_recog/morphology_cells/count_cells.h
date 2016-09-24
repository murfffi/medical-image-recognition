#pragma once

#include "detector.h"

namespace img_recog {
	class CountCells : public Detector {
	public:
		CountCells(cimg_library::CImgDisplay& display, int approxCellRadius)
			: display(display), approxCellRadius(approxCellRadius)
		{}

		virtual int detectIn(const CImgBmp& image);
	private:
		cimg_library::CImgDisplay& display;
		int approxCellRadius;
	};
}
