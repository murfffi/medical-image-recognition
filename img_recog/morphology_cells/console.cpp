#include <iostream>
#include <string>

using namespace std;

namespace img_recog {
namespace console {
	void prompt(const char* msg) {
		if (msg != 0)
			cout << msg << std::endl;
		cout << "Press enter to continue ..." << std::endl;
		string dummy;
		getline(cin, dummy);
	}
} }
