#pragma once

#include "filter.h"

namespace img_recog {
	class Imposer : public Filter {
	public:		
		Imposer(const CImgBmp& imageToImpose, int layerToSubs = 1) 
			: imageToImpose(imageToImpose), layerToSubs(layerToSubs)
		{}

		virtual void filter(CImgBmp& image) const;

	private:
		//copy construction is forbidden
		Imposer(const Imposer&);
		//assignmet is forbidden
		Imposer& operator=(const Imposer&);

		const CImgBmp& imageToImpose;
		int layerToSubs;
	};
}
