#pragma once

#ifdef Render_EXPORTS
#define Render_API __declspec(dllexport)

#else
#define Render_API __declspec(dllimport)
#endif

namespace gaia {
	Render_API void PrintMessage();
}