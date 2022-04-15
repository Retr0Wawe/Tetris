#pragma once

#include <array>

#include "Defines.hpp"

#include "Figure.hpp"

namespace game
{
	class IFieldConsole		//������� ����������� ����� ���� �� �������� ����� ������������� ����� ���� ���������� ���
	{
	public:
		IFieldConsole();

		IFieldConsole(int _field_char, int _figure_char);	
					//����������� ��� ������������� ���������� ��� ��������� � ����� ascii �����

		virtual ~IFieldConsole() = default;	//����. ����������� ����� �� �������� ������� ������� �������� ��� ������������
	public:
		virtual void print() = 0;	//������ ����������� ������� ��� ���������������

		virtual void clear_screen(int _sym) = 0;

		virtual bool key_handler(eKeys _key) = 0;
	protected:
		double_array<int, field_x, field_y> field = { 0 };	//����. ����������� ������ ����, ���������� ��� ������ ���������� ���
		char field_char, figure_char;
	};

	class Tetris : public IFieldConsole		//�������� ��������� ����� Field ��� ���� ��� �������������� ������� ���������
	{
		friend class Figure;
	public:
		Tetris() = default;

		Tetris(Figure& _figura, int _field_char = 183, int _figure_char = 20);

		~Tetris() = default;
	public:
		void print() override;	//��������� ����

		void clear_screen(int _sym = 0) override;	//������� ������

		bool key_handler(eKeys _key) override;		//���������� �������

		static void print_next_figure();	//���������� ��������� ������

		void start();		//��������� ����
	private:
		Figure figura;		//������ ������ ����� ����� ����� ������ � ��������� ������ ������
	};
}