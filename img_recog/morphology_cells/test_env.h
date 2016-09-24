#include "cimg_bmp.h"

namespace img_recog {
	struct SnapshotInfo;
namespace test {
	class TestEnv {
	public:
		TestEnv();
		TestEnv(const SnapshotInfo& info);
		CImgBmp createCellsImage() {
			return CImgBmp(cellsImageFilename);
		}
		cimg_library::CImgDisplay& getMainDisplay() {
			return mainDisplay;
		}
	private:
		cimg_library::CImgDisplay mainDisplay;
		const char* cellsImageFilename;

		void moveDisplayToInitial();
	};
} }
