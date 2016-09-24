#pragma once

#include "filter.h"

namespace img_recog {
	class GradientFilter : public Filter {
	public:
		virtual void filter(CImgBmp& image) const;
	};
}
