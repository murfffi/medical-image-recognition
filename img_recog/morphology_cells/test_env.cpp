#include "test_env.h"
#include "snapshot_info.h"

namespace img_recog {
namespace test {

	namespace {
		const char * WINDOW_TITLE = "Morphology View";
		const char * DEFAULT_CELLS_IMAGE_FILENAME = "blood1.bmp";
		const int windowW = 640;
		const int windowH = 480;
	}

	TestEnv::TestEnv() 
		: mainDisplay(windowW, windowH, WINDOW_TITLE),  cellsImageFilename(DEFAULT_CELLS_IMAGE_FILENAME)
	{
		moveDisplayToInitial();
	}

	TestEnv::TestEnv(const SnapshotInfo& info) 
		: mainDisplay(windowW, windowH, WINDOW_TITLE),  cellsImageFilename(info.fileName.c_str())
	{
		moveDisplayToInitial();
	}

	void TestEnv::moveDisplayToInitial() {
		mainDisplay.move(mainDisplay.screen_dimx() - windowW - 3, mainDisplay.screen_dimy() - windowH - 60);
	}

} }
