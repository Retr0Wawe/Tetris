#pragma once

#include <cstddef>

namespace game
{
	namespace utils
	{
		std::size_t randomize(std::size_t _num);	 //рандомайзер для случайного значения

		void sleep(int _seconds);	//задержка

		int inverse(int _x);		//обратное получение координаты
	}
}