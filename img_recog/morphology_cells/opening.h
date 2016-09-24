#pragma once

#include "filter.h"

namespace img_recog {
	class Opening : public Filter {
	public:
		Opening(int structCircleDiameter) : structCircleDiameter(structCircleDiameter)
		{}

		virtual void filter(CImgBmp& image) const;

	private:
		CImgBmp createStructElem() const;
		int structCircleDiameter;
	};
}
