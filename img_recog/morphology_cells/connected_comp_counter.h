#pragma once

#include "detector.h"

namespace img_recog {
	class ConnectedCompCounter : public Detector {
	public:
		ConnectedCompCounter(bool k8Connectivity = true) : k8Connectivity(k8Connectivity)
		{}

		virtual int detectIn(const CImgBmp& image);
	private:
		bool k8Connectivity;
	};
}
