#include "Game.hpp"
#include <cstdint>

using namespace game;

int main()
{
	Figure fi;		//������ ������
	Tetris tetr(fi, 183, 20);
	//����������� ��������� �������, � �������� ����������: ������ ������ � ���� �������� ��� ��������� 

	tetr.start();		//������ ����
}