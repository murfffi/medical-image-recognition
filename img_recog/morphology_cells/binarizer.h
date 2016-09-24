#pragma once 

#include "filter.h"

namespace img_recog {
	class Binarizer : public Filter {
	public:
		virtual void filter(CImgBmp& image) const;
	protected:
		virtual double getThresholdFor(const CImgBmp& image) const=0;
	};
}
