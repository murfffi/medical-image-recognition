#pragma once

#include "filter.h"

namespace img_recog {
	class HistogramGraphBuilder : public Filter {
	public:
		HistogramGraphBuilder(unsigned int graphType = 1)
			: graphType(graphType)
		{}

		virtual void filter(CImgBmp& image) const;
	private:
		unsigned int graphType;
	};
}
