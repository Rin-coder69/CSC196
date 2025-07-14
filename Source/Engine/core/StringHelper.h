#pragma once
#include <string>

namespace gaia {

	/// <summary>
	/// Converts all characters in a string to uppercase.
	/// </summary>
	/// <param name="str">The input string to convert.</param>
	/// <returns>A new string with all characters converted to uppercase.</returns>
	inline std::string ToUpper(const std::string& str) {
		std::string upperStr = str;
		for (char& c : upperStr) {
			c = std::toupper(c);
		}
		return upperStr;
	}
}