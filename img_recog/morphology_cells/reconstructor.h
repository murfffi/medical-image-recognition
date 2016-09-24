#pragma once

#include "filter.h"

namespace img_recog {
	class Reconstructor : public Filter {
	public:
		Reconstructor(CImgBmp& original) : original(original, false)
		{}

		virtual void filter(CImgBmp& image) const;
	private:
		CImgBmp original;
	};
}
