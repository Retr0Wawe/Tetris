#pragma once

#include <array>

#include "Defines.hpp"

#include "Figure.hpp"

namespace game
{
	class IFieldConsole		//создаем абстрактный класс поле от которого могут наследоваться любые типы консольных игр
	{
	public:
		IFieldConsole();

		IFieldConsole(int _field_char, int _figure_char);	
					//конструткор для инициализации переменных для отрисовки в ввиде ascii кодов

		virtual ~IFieldConsole() = default;	//вирт. десктруктор чтобы не нарушать порядок очистки обьектов при наследовании
	public:
		virtual void print() = 0;	//чистая виртуальная функция для переопределения

		virtual void clear_screen(int _sym) = 0;

		virtual bool key_handler(eKeys _key) = 0;
	protected:
		double_array<int, field_x, field_y> field = { 0 };	//двум. статический массив поля, характерен для многих консольных игр
		char field_char, figure_char;
	};

	class Tetris : public IFieldConsole		//публично наследуем класс Field для того что переопределить функции отрисовки
	{
		friend class Figure;
	public:
		Tetris() = default;

		Tetris(Figure& _figura, int _field_char = 183, int _figure_char = 20);

		~Tetris() = default;
	public:
		void print() override;	//отрисовка поля

		void clear_screen(int _sym = 0) override;	//очистка экрана

		bool key_handler(eKeys _key) override;		//обработчик нажатий

		static void print_next_figure();	//напечатать следующую фигуру

		void start();		//запустить игру
	private:
		Figure figura;		//обьект фигуры нужен чтобы иметь доступ к приватным членам класса
	};
}