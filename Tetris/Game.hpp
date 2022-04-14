#pragma once

#include <array>
#include <windows.h>
#include <random>

#include "Defines.hpp"

namespace game
{
	class IFieldConsole		//������� ����������� ����� ���� �� �������� ����� ������������� ����� ���� ���������� ���
	{
	public:
		IFieldConsole() = default;

		virtual ~IFieldConsole() = default;	//����. ����������� ����� �� �������� ������� ������� �������� ��� ������������
	public:
		virtual void print() = 0;	//������ ����������� ������� ��� ���������������

		virtual void clear_screen() = 0;

		virtual void key_handler(eKeys _key) = 0;
	protected:
		double_array<int, field_x, field_y> field = { 0 };	//����. ����������� ������ ����, ���������� ��� ������ ���������� ���
	};

	class Tetris : public IFieldConsole	//�������� ��������� ����� Field ��� ���� ��� �������������� ������� ���������
	{
	public:
		Tetris() = default;

		~Tetris() = default;
	public:
		void print() override;	//��������� ����

		void clear_screen() override;	//������� ������

		void key_handler(eKeys _key) override;

		void delete_line();		//������� ��������� �����

		void start();	//��������� ����
	};
}