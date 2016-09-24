#include "histogram_graph_builder.h"
#include "grayscale_filter.h"
#include <cassert>

namespace img_recog {
	void HistogramGraphBuilder::filter(img_recog::CImgBmp &image) const {
		if (image.dimv() > 1)
			image << GrayscaleFilter();
		assert(image.dimv() == 1);
		cimg_library::CImg<float> histogram = image.get_histogram();
		image.fill(0);
		CImgBmp::value_type foreColor = 255;
		image.draw_graph(histogram, &foreColor, graphType);
	}
}
