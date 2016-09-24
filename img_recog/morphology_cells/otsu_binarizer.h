#pragma once 

#include "binarizer.h"

namespace img_recog {
	class OtsuBinarizer : public Binarizer {
	protected:
		virtual double getThresholdFor(const CImgBmp& image) const;
	};
}
