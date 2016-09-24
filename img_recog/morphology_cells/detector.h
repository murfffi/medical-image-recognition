#pragma once

#include "cimg_bmp.h"

namespace img_recog {
	class Detector {
	public:
		virtual int detectIn(const CImgBmp& img)=0;
	};
}
