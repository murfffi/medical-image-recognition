#pragma once

#include "filter.h"

namespace img_recog {
	class HoughCircles : public Filter {
	public:
		HoughCircles(int radius) : radius(radius)
		{}

		virtual void filter(CImgBmp& image) const;

	private:
		int radius;
	};
}
