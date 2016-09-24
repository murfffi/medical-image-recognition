#include "connected_comp_counter.h"
#include "connected.h"
#include "image_exception.h"
#include <functional>

namespace img_recog {
	namespace {
		class scoped_image_array {
		public:
			scoped_image_array(int size) : arr(new int[size])
			{}

			~scoped_image_array() {
				delete [] arr;
			}

			int* get() {
				return arr;
			}
		private:
			int * const arr;
		};
	}

	int ConnectedCompCounter::detectIn(const CImgBmp& image) {
		if (image.dimv() > 1)
			throw ImageException("Images with more than one color layer are not supported by this detector.");

		if (image.dimz() > 1)
			throw ImageException("3D images are not supported by this detector.");

		ConnectedComponents cc(1000);
		scoped_image_array out_uc(image.dimx() * image.dimy());
		int connectedComponents = cc.connected(image.ptr(), out_uc.get(), image.dimx(), image.dimy(),
			 std::equal_to<unsigned char>(),
			 k8Connectivity);


		return connectedComponents;
	}
}
