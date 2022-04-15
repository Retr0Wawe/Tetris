#pragma once

#include "Defines.hpp"

namespace game
{
    constexpr int figurs_sample[figure_counts][figure_size][figure_size] =     
        //������������� ����� �������, 1 - �����������, 0 - ���
    {
        {
            {1, 1, 0, 0},
            {1, 0, 0, 0},
            {0, 0, 0, 0},
            {0, 0, 0, 0}
        },
        {
            {1, 0, 0, 0},            //����� ��������� ���� ������, ���������� �� �� ������
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

    class Tetris;   //���������� ������ ������

	class Figure	//����� ����� ��� ������� ������������� � ������ � ����
	{
        friend class Tetris;
	public:
		Figure() = default;

		virtual ~Figure() = default;	//����. ���������� �� ���������
	public:
        virtual void create();      //�������� ������

		virtual void rotate();      //����������� ������

		virtual bool get_move(const Tetris& _tet, int _x, int _y);    //���������� ����
	protected:
		double_array<int, figure_size> figure_field = { 0 };     //������ ��� �����
        static inline int next_map;
	};
}