#pragma once

#include <time.h>
#include <windows.h>
#include <random>

namespace game
{
	namespace utils
	{
		std::size_t randomize(std::size_t _num)
		{
			srand(time(NULL));
			return rand() % _num;
		}

		void sleep(int _seconds) 
		{
			clock_t t = clock();
			while (clock() - t < _seconds);
		}
	}
}