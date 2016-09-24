#include "test.h"
#include "test_env.h"
#include "count_cells.h"
#include "count_cells_angulo.h"
#include "console.h"
#include "snapshot_info.h"
#include <iostream>

namespace img_recog {
namespace test {

	void countCells(const SnapshotInfo& info) {
		TestEnv env(info);
		CImgBmp image(env.createCellsImage());
		env.getMainDisplay() << image;
		console::prompt();

		CountCells countCells(env.getMainDisplay(), info.approxCellRadius);
		int cellsNumber = countCells.detectIn(image);
		std::cout << cellsNumber << " cells found.\n";
	}

	void countCellsAngulo(const SnapshotInfo& info) {
		TestEnv env(info);
		CImgBmp image(env.createCellsImage());
		env.getMainDisplay() << image;
		console::prompt();

		CountCellsAngulo countCells(env.getMainDisplay(), info.approxCellRadius);
		int cellsNumber = countCells.detectIn(image);
		std::cout << cellsNumber << " cells found.\n";
	}
} }
