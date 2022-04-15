#pragma once

#include <cstddef>

namespace game
{
	namespace utils
	{
		void cursor_to_xy(int _x, int _y);		//перевод курсора по координатам

		std::size_t randomize(std::size_t _num);		//рандомайзер для случайного значения

		void sleep(int _seconds);	//задержка

		int inverse(int _x);		//обратное получение координаты
	}
}