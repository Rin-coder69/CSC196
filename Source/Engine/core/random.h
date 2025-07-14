#pragma once
#include <cstdlib>
namespace gaia {

	namespace Random {

		/// <summary>
		/// Generates a random integer value.
		/// </summary>
		/// <returns>A pseudo-random integer value.</returns>
		inline int getRandomInt() {
			return rand();
		}
		/// <summary>
		/// Generates a random integer value in the range [0, max).
		///
		int getRandomInt(int max) {
			return rand() % max;
		}
		/// <summary>
		/// Generates a random integer within a specified inclusive range.
		/// </summary>
		/// <param name="min">The lower bound of the range (inclusive).</param>
		/// <param name="max">The upper bound of the range (inclusive).</param>
		/// <returns>A random integer between min and max, inclusive.</returns>
		 inline int getRandomInt(int min, int max) {
			return min + getRandomInt(max - min + 1);
		}
		 /// <summary>
		 /// Generates a random floating-point number between 0 and 1.
		 /// </summary>
		 /// <returns>A random float value in the range [0, 1].</returns>
		 inline float getRandomFloat() {
			 
			return (float)rand()/RAND_MAX;
		}
	}
}