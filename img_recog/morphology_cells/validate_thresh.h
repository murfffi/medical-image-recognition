namespace img_recog {
namespace {
	void validateThresh(int& thresh, const CImgBmp& image) {
		double percentWhite = 0;
		int pixelsWhite =0, totalPixels = image.dimx() * image.dimy();
		while (percentWhite < 30) {
			pixelsWhite = 0;
			cimg_forV (image, v) {
				cimg_forXY (image, x, y) {
					if (image(x, y, v) >= thresh)
						++pixelsWhite;
				}
			}
			percentWhite = (double)pixelsWhite / totalPixels * 100;
			--thresh;
		}
	}
} }