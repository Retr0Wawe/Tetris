#include "Game.hpp"
#include "Defines.hpp"
#include "Utils.hpp"
#include "Figure.hpp"

#include <stdio.h>
#include <time.h>
#include <conio.h>

namespace game
{
	IFieldConsole::IFieldConsole() : field_char(NULL), figure_char(NULL)
	{	}

	IFieldConsole::IFieldConsole(int _field_char, int _figure_char) :
		field_char(char(_field_char)), figure_char(char(_figure_char))
	{	}						//инициализация переменных

	//////////////////////////////////

	Tetris::Tetris(Figure& _figura, int _field_char, int _figure_char) :
		figura(_figura), IFieldConsole(_field_char, _figure_char)
	{	}						//инициализация переменных

	void Tetris::print()
	{
		int buff[field_x][field_y];

		for (int i = 0; i < field_x; i++) {
			for (int j = 0; j < field_y; j++) {
				buff[j][i] = field[j][i];			//вывод из буфера на экран
			}
		}

		for (int i = 0; i < figure_size; i++) {
			for (int j = 0; j < figure_size; j++) {
				if (figura.figure_field[j][i]) {
					buff[j + px][i + py] = 1;		//если часть фигуры, то в буфере обозначить 1
				}
			}
		}

		for (int i = 0; i < field_y; i++) {
			for (int j = 0; j < field_x; j++) {
				putchar(buff[j][i] == 0 ? field_char : figure_char); //если элемент в буфере не часть фигуры, то закрасить полем
			}
			putchar('\n');
		}
		system("cls");		//очищаем экран чтобы создать нужный эффект отрисовки
	}

	bool Tetris::key_handler(eKeys _key)
	{
		switch (_key)		//исходя из ключа, проходим в нужный case
		{
		case eKeys::KEY_UP:		//переворот фигуры если нажата клавиша
			figura.rotate();
			break;
		case eKeys::KEY_SPACE:	//переворот фигуры если нажата клавиша
			figura.rotate();
			break;
		case eKeys::KEY_DOWN:	//движение вниз
			while (figura.get_move(*this, px, py + 1)) {
				py++;
			}
			for (int i = 0; i < figure_size; i++) {		//отрисовка фиугры внизу поля
				for (int j = 0; j < figure_size; j++) {
					if (figura.figure_field[j][i]) {
						field[px + j][py + i] = 1;
					}
				}
			}
			print();		//отрисовка фигуры
			figura.create();	//создание следующей
			break;
		case eKeys::KEY_LEFT:	//движение влево
			if (figura.get_move(*this, px - 1, py)) {
				px--;		//смещение фигуры влево(по координате x)
			}
			break;
		case eKeys::KEY_RIGHT:	//движение вправо
			if (figura.get_move(*this, px + 1, py)) {
				px++;		//смещаем положение фигуры вправо(по координате x)
			}
			break;
		}
		return false;
	}

	void Tetris::print_next_figure()	//напечатать следуюущую фигуру
	{
		for (int i = 0; i < figure_size; i++) {
			for (int j = 0; j < figure_size; j++) {
				putchar(figurs_sample[Figure::next_figure][j][i] == 0 ? ' ' : 20); //если не часть фигуры, то закрасить символом поля, иначе закрасить фигурой
			}
		}
	}

	void Tetris::start()
	{
		time_t time = clock();		//берем начало времени

		px = field_x / 2;
		py = 0;

		Figure::next_figure = utils::randomize(figure_counts);		//рандомно выбираем любую фигуру
		figura.create();		//создание фигуры

		while (true) {			//цикл отрисовки
			if (_kbhit()) {
				key_handler(eKeys(_getch()));		//обработка нажатий
			}

			if ((clock() - time) > 100) {
				time = clock();
				if (!(figura.get_move(*this, px, py + 1))) {		//если фигура не двигается то отрисовывать поле
					for (int i = 0; i < figure_size; i++) {
						for (int j = 0; j < figure_size; j++) {
							if (figura.figure_field[j][i]) {
								field[px + j][py + i] = 1;		//закрашиваем поле
							}
						}
					}
					figura.create();	//создаеи следующую фигуру
				}
				else {
					py++;
				}
			}
			print();	//смещение фигуры вниз относительно таймера, если не было никаких действийfor(int i = 0; i < SIZEX; i++) 

			for (int i = 0; i < field_x; i++) {
				if (field[i][0])//если экранный у и у фигуры совпали и равны 0,то конец игры ,поле заполнилось до верха
				{
					return;
				}
			}
		}
	}
}