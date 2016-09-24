#include "test.h"
#include "test_env.h"
#include "console.h"
#include "grayscale_filter.h"

namespace img_recog {
namespace test {

	void grayscale() {
		TestEnv env;
		CImgBmp image(env.createCellsImage());
		env.getMainDisplay() << image;
		console::prompt();

		image << GrayscaleFilter();
		env.getMainDisplay() << image;
		console::prompt();
	}
} }
