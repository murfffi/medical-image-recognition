#pragma once

namespace img_recog {
	struct SnapshotInfo;

namespace test {
	void grayscale();
	void countCells(const SnapshotInfo& info);
	void countCellsAngulo(const SnapshotInfo& info);
	void test_inline_img();
} }
