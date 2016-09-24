#include "close_hole_filter.h"
#include "reconstructor.h"
#include "console.h"
#include "gradient_filter.h"

namespace img_recog {
	void CloseHoleFilter::filter(img_recog::CImgBmp &image) const {
		CImgBmp inverted(~image);
		display << inverted;
		console::prompt("Close hole : inverted");
		
		image = inverted;
		CImgBmp::value_type black = 0;
		image.draw_rectangle(1, 1, image.dimx() - 2, image.dimy() - 2, &black);
		display << image;
		console::prompt("Close hole : border");

		image << Reconstructor(inverted);
		image = ~image;
	}
}
