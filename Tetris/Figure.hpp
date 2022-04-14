#pragma once

#include "Defines.hpp"

namespace game
{
	class Figure	//класс фигур для удобной инициализации и работы с ними
	{
	public:
		Figure() = default;

		virtual ~Figure() = default;	//вирт. деструктор по умолчанию
	public:
		void rotate();

		void get_down();
	public:
		double_array<int, figure_size> map = { 0 };
	};
}