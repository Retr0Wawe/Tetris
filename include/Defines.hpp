#pragma once

#include <array>
#include <cstdint>

namespace game
{
	//все переменные считаются на этапе компиляции чтобы не занимать runtime'а(то есть сделать пронга)
	
	inline int py, px = 0;		//переменные - координаты относительно которых перемещаются фигуры по x, y

	constexpr int figure_counts = 4;	//количество фигур тетриса
	constexpr int figure_size = 4;

	constexpr std::size_t field_x = 20;		//переменные хранящие разрешение поля
	constexpr std::size_t field_y = 20;

	template<typename _T, std::size_t _X, std::size_t _Y = _X>	//псевдоним для двумерного массива с шаблонными параметрами
	using double_array = std::array<std::array<_T, _X>, _Y>;	
	//если нам не нужен массив с разными размерами, то просто присваем значение _X значению _Y(параметр по умолчанию)

	enum class eKeys : unsigned int		//определяем перечисление клавиш
	{
		KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77,
		KEY_SPACE = 32, KEY_ESC = 27, KEY_ENTER = 13
	};
}