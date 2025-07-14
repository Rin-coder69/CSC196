#pragma once
#include <string>

namespace gaia {
	
		// Converts a string to uppercase
		inline std::string ToUpper(const std::string& str) {
			std::string upperStr = str;
			for (char& c : upperStr) {
				c = std::toupper(c);
			}
			return upperStr;
		}
	}
};