#include "otsu_binarizer.h"
#include "validate_thresh.h"

#include <cassert>
#include <iostream>

namespace img_recog {
	double OtsuBinarizer::getThresholdFor(const img_recog::CImgBmp &image) const {
		int thresh;
		double criterion;
		double expr_1;
		int i, k;
		double omega_k;
		double sigma_b_k;
		double sigma_T;
		double mu_T;
		double mu_k;
		int k_low, k_high;
		const int NB_LEVELS = 256;
		cimg_library::CImg<float> histogram = image.get_histogram(NB_LEVELS);
		assert(histogram.dimy() == 1);
		assert(histogram.dimz() == 1);
		assert(histogram.dimv() == 1);
		assert(histogram.dimx() == NB_LEVELS);
		histogram /= image.dimx() * image.dimy();
		float* p = histogram.ptr();
		mu_T = 0.0;
		for (i=0; i<NB_LEVELS; i++)
		mu_T += i*p[i];

		sigma_T = 0.0;
		for (i=0; i<NB_LEVELS; i++)
		sigma_T += (i-mu_T)*(i-mu_T)*p[i];


		for (k_low = 0; (p[k_low] == 0) && (k_low < NB_LEVELS - 1); k_low++);
		for (k_high = NB_LEVELS - 1; (p[k_high] == 0) && (k_high > 0); k_high--);

		criterion = 0.0;
		thresh = NB_LEVELS / 2;

		omega_k = 0.0;
		mu_k = 0.0;
		for (k = k_low; k <= k_high ; k++)
		{
			omega_k += p[k];
			mu_k += k*p[k];

			expr_1 = (mu_T*omega_k - mu_k);
			sigma_b_k = expr_1 * expr_1 / (omega_k*(1-omega_k));
			//sigma_b_k = (mu_T - mu_k) * (mu_T - mu_k) * omega_k + mu_k * mu_k * (1 - omega_k);
			if (criterion < sigma_b_k/sigma_T)
			{
				criterion = sigma_b_k/sigma_T;
				thresh = k;
			}
		}

		validateThresh(thresh, image);
		std::cout << "Otsu threshold at " << thresh << std::endl;
		return thresh;
	}
}
