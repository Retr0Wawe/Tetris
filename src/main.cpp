#include "Game.hpp"
#include <cstdint>

using namespace game;

int main()
{
	Figure fi;		//������ ������
	Tetris tetr(fi, '#', 'f');
	//����������� ��������� �������, � �������� ����������: ������ ������ � ���� �������� ��� ��������� 

	tetr.start();		//������ ����
}