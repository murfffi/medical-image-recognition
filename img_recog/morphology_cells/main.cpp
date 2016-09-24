#include "test.h"
#include "snapshot_factory.h"
#include <cstring>

using namespace img_recog;
int main(int argc, char* argv[]) {
	SnapshotInfo info(snapshot_factory::loadSnapshot(argc, argv));
	if (argc >= 3 && strcmp(argv[2], "angulo") == 0)
		test::countCellsAngulo(info);
	else
		test::countCells(info);
	//img_recog::test::grayscale();
	//img_recog::test::test_inline_img();
	return 0;
}
