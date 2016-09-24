#include "count_cells.h"
#include "console.h"
#include "simple_binarizer.h"
#include "otsu_binarizer.h"
#include "hough_circles_range.h"
#include "imposer.h"
#include "gradient_filter.h"
#include "connected_comp_counter.h"
#include "histogram_graph_builder.h"

#include <cassert>

namespace img_recog {
	using cimg_library::CImgList;

	int CountCells::detectIn(const CImgBmp& original) {
		CImgBmp image(original, false);
		image.channel(1); //get green channel
		display << image;
		console::prompt();
		assert(image.dimv() == 1);

		image.blur_median(); //n=3
		display << image;
		console::prompt();

		CImgBmp forHistogram(image, false);
		forHistogram << HistogramGraphBuilder();
		display << forHistogram;
		console::prompt("Histogram.");

		image << OtsuBinarizer();//SimpleBinarizer(150);
		image = ~image; //invert
		display << image;
		console::prompt("Binary inverted image. Cells are white.");
		
		image << GradientFilter();
		display << image;
		console::prompt("Gradient.");

		image << HoughCirclesRange(approxCellRadius);
		display << image;
		console::prompt("Centers");

		display << original;
		console::prompt("Original again");

		CImgBmp withCenters(original, false);
		withCenters << Imposer(image);
		display << withCenters;
		console::prompt("Green centers superimposed on original.");

		ConnectedCompCounter ccc;
		int connectedComponents = ccc.detectIn(image);
		return connectedComponents;
	}
}
