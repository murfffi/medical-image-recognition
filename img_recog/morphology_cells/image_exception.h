#pragma once

#include <stdexcept>
#include <string>

namespace img_recog {
	class ImageException : public std::exception {
	public:
		ImageException(const std::string& msg) : std::exception(msg.c_str())
		{}

		ImageException(const std::string& msg, const std::exception& inner)
			: std::exception((msg + "Caused by: " + inner.what()).c_str())
		{}
	};
}
