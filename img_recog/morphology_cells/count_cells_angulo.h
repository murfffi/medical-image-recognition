#pragma once

#include "detector.h"

namespace img_recog {
	class CountCellsAngulo : public Detector {
	public:	
		CountCellsAngulo(cimg_library::CImgDisplay& display, int approxCellRadius)
			: display(display), approxCellRadius(approxCellRadius)
		{}

		virtual int detectIn(const CImgBmp& image);
	private:
		cimg_library::CImgDisplay& display;
		int approxCellRadius;
	};
}
