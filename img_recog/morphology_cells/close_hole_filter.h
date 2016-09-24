#pragma once

#include "filter.h"

namespace img_recog {
	class CloseHoleFilter : public Filter {
	public:		
		CloseHoleFilter(cimg_library::CImgDisplay& display)
			: display(display)
		{}

		virtual void filter(CImgBmp& image) const;

	private:
		cimg_library::CImgDisplay& display;

	};
}
