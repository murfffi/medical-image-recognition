#include "snapshot_factory.h"
#include "simple_ini.h"
#include <cassert>
#include <cstdlib>

namespace img_recog {
namespace snapshot_factory {
	namespace {
		const char * DEFAULT_CONFIG = "blood1.ini";
	}

	SnapshotInfo loadSnapshot(int argc, char* argv[]) {
		CSimpleIniA iniFile;
		const char * fileName;
		if (argc < 2)
			fileName = DEFAULT_CONFIG;
		else
			fileName = argv[1];
		iniFile.LoadFile(fileName);
		CSimpleIniA::TNamesDepend sections;
		iniFile.GetAllSections(sections);
		assert(sections.size() > 0);
		const char * firstSectionName = sections.front().pItem;

		SnapshotInfo info = {
			std::string(iniFile.GetValue(firstSectionName, "FileName")),
			atoi(iniFile.GetValue(firstSectionName, "ApproxCellRadius"))
		};
		return info;
	}
} }
