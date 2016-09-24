#include "count_cells_angulo.h"
#include "console.h"
#include "otsu_binarizer.h"
#include "reconstructor.h"
#include "opening.h"
#include "close_hole_filter.h"
#include "connected_comp_counter.h"
#include <cassert>

namespace img_recog {
	int CountCellsAngulo::detectIn(const CImgBmp& img) {
		CImgBmp image(img, false);
		image.channel(1); //get green channel
		display << image;
		console::prompt();
		assert(image.dimv() == 1);

		image.blur_median(); //n=3
		display << image;
		console::prompt();

		image << OtsuBinarizer();
		image = ~image;
		display << image;
		console::prompt();

		//remove platelets and artefacts
		Reconstructor recons(image);
		image << Opening(approxCellRadius);
		display << image;
		console::prompt();
		image << recons;
		display << image;
		console::prompt("Removed platelets and artefacts.");

		image << CloseHoleFilter(display);
		display << image;
		console::prompt("Close hole : done");

		ConnectedCompCounter ccc(false);
		int connectedComponents = ccc.detectIn(image);
		return connectedComponents;
	}
}
