#pragma once 

#include "binarizer.h"

namespace img_recog {
	class SimpleBinarizer : public Binarizer {
	public:
		SimpleBinarizer(double threshold) 
			: threshold(threshold)	 
		{}
	protected:
		virtual double getThresholdFor(const CImgBmp&) const {
			return threshold;
		}
	private:
		double threshold;
	};
}
