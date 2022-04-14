#pragma once

#include "Defines.hpp"

namespace game
{
	class Figure	//����� ����� ��� ������� ������������� � ������ � ����
	{
	public:
		Figure() = default;

		virtual ~Figure() = default;	//����. ���������� �� ���������
	public:
		void rotate();

		void get_down();
	public:
		double_array<int, figure_size> map = { 0 };
	};
}