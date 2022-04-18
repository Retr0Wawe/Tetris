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
	{	}						//������������� ����������

	//////////////////////////////////

	Tetris::Tetris(Figure& _figura, int _field_char, int _figure_char) :
		figura(_figura), IFieldConsole(_field_char, _figure_char)
	{	}						//������������� ����������

	void Tetris::print()
	{
		int buff[field_x][field_y];

		for (int i = 0; i < field_x; i++) {
			for (int j = 0; j < field_y; j++) {
				buff[j][i] = field[j][i];			//����� �� ������ �� �����
			}
		}

		for (int i = 0; i < figure_size; i++) {
			for (int j = 0; j < figure_size; j++) {
				if (figura.figure_field[j][i]) {
					buff[j + px][i + py] = 1;		//���� ����� ������, �� � ������ ���������� 1
				}
			}
		}

		for (int i = 0; i < field_y; i++) {
			for (int j = 0; j < field_x; j++) {
				putchar(buff[j][i] == 0 ? field_char : figure_char); //���� ������� � ������ �� ����� ������, �� ��������� �����
			}
			putchar('\n');
		}
		system("cls");		//������� ����� ����� ������� ������ ������ ���������
	}

	bool Tetris::key_handler(eKeys _key)
	{
		switch (_key)		//������ �� �����, �������� � ������ case
		{
		case eKeys::KEY_UP:		//��������� ������ ���� ������ �������
			figura.rotate();
			break;
		case eKeys::KEY_SPACE:	//��������� ������ ���� ������ �������
			figura.rotate();
			break;
		case eKeys::KEY_DOWN:	//�������� ����
			while (figura.get_move(*this, px, py + 1)) {
				py++;
			}
			for (int i = 0; i < figure_size; i++) {		//��������� ������ ����� ����
				for (int j = 0; j < figure_size; j++) {
					if (figura.figure_field[j][i]) {
						field[px + j][py + i] = 1;
					}
				}
			}
			print();		//��������� ������
			figura.create();	//�������� ���������
			break;
		case eKeys::KEY_LEFT:	//�������� �����
			if (figura.get_move(*this, px - 1, py)) {
				px--;		//�������� ������ �����(�� ���������� x)
			}
			break;
		case eKeys::KEY_RIGHT:	//�������� ������
			if (figura.get_move(*this, px + 1, py)) {
				px++;		//������� ��������� ������ ������(�� ���������� x)
			}
			break;
		}
		return false;
	}

	void Tetris::print_next_figure()	//���������� ���������� ������
	{
		for (int i = 0; i < figure_size; i++) {
			for (int j = 0; j < figure_size; j++) {
				putchar(figurs_sample[Figure::next_figure][j][i] == 0 ? ' ' : 20); //���� �� ����� ������, �� ��������� �������� ����, ����� ��������� �������
			}
		}
	}

	void Tetris::start()
	{
		time_t time = clock();		//����� ������ �������

		px = field_x / 2;
		py = 0;

		Figure::next_figure = utils::randomize(figure_counts);		//�������� �������� ����� ������
		figura.create();		//�������� ������

		while (true) {			//���� ���������
			if (_kbhit()) {
				key_handler(eKeys(_getch()));		//��������� �������
			}

			if ((clock() - time) > 100) {
				time = clock();
				if (!(figura.get_move(*this, px, py + 1))) {		//���� ������ �� ��������� �� ������������ ����
					for (int i = 0; i < figure_size; i++) {
						for (int j = 0; j < figure_size; j++) {
							if (figura.figure_field[j][i]) {
								field[px + j][py + i] = 1;		//����������� ����
							}
						}
					}
					figura.create();	//������� ��������� ������
				}
				else {
					py++;
				}
			}
			print();	//�������� ������ ���� ������������ �������, ���� �� ���� ������� ��������for(int i = 0; i < SIZEX; i++) 

			for (int i = 0; i < field_x; i++) {
				if (field[i][0])//���� �������� � � � ������ ������� � ����� 0,�� ����� ���� ,���� ����������� �� �����
				{
					return;
				}
			}
		}
	}
}