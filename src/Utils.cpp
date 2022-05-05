#include "Utils.hpp"

#include <time.h>
#include <windows.h>
#include <random>

namespace game
{
	namespace utils
	{
		std::size_t randomize(std::size_t _num)		//рандомайзер для случайного значения
		{
			srand(time(NULL));
			return rand() % ++_num;
		}

		void sleep(int _seconds)	//задержка
		{
			clock_t t = clock();
			while (clock() - t < _seconds);
		}

		int inverse(int _x)		//обратное получение координаты
		{
			return 3 - _x;
		}
	}
}