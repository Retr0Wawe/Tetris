#pragma once

#include <array>
#include <windows.h>
#include <random>

#include "Defines.hpp"

namespace game
{
	class IFieldConsole		//создаем абстрактный класс поле от которого могут наследоваться любые типы консольных игр
	{
	public:
		IFieldConsole() = default;

		virtual ~IFieldConsole() = default;	//вирт. десктруктор чтобы не нарушать порядок очистки обьектов при наследовании
	public:
		virtual void print() = 0;	//чистая виртуальная функция для переопределения

		virtual void clear_screen() = 0;

		virtual void key_handler(eKeys _key) = 0;
	protected:
		double_array<int, field_x, field_y> field = { 0 };	//двум. статический массив поля, характерен для многих консольных игр
	};

	class Tetris : public IFieldConsole	//публично наследуем класс Field для того что переопределить функции отрисовки
	{
	public:
		Tetris() = default;

		~Tetris() = default;
	public:
		void print() override;	//отрисовка поля

		void clear_screen() override;	//очистка экрана

		void key_handler(eKeys _key) override;

		void delete_line();		//удалить собранную линию

		void start();	//запустить игру
	};
}