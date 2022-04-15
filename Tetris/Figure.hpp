#pragma once

#include "Defines.hpp"

namespace game
{
    constexpr int figurs_sample[figure_counts][figure_size][figure_size] =     
        //инициализация фигур тетриса, 1 - закрашивать, 0 - нет
    {
        {
            {1, 1, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {1, 0, 0, 0},            //можно добавлять свои фигуры, выстраивая их из единиц
            {1, 0, 0, 0},
            {1, 0, 0, 0},
            {1, 0, 0, 0}
        },
        {
            {0, 0, 1, 0},
            {1, 1, 1, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        }
    };

    class Tetris;   //декларация класса тетрис

	class Figure	//класс фигур для удобной инициализации и работы с ними
	{
        friend class Tetris;
	public:
		Figure() = default;

		virtual ~Figure() = default;	//вирт. деструктор по умолчанию
	public:
        virtual void create();      //создание фигуры

		virtual void rotate();      //перевернуть фигуру

		virtual bool get_move(const Tetris& _tet, int _x, int _y);    //опуститься вниз
	protected:
		double_array<int, figure_size> figure_field = { 0 };     //массив для фигур
        static inline int next_map;
	};
}