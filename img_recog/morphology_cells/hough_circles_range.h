#pragma once

#include "filter.h"

namespace img_recog {
	class HoughCirclesRange : public Filter {
	public:		
		HoughCirclesRange(int radius);
		virtual void filter(CImgBmp& image) const;

	private:
		int radiusMin;
		int radiusMax;
	};
}
