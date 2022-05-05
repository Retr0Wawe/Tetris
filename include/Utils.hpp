#pragma once

#include <cstddef>

namespace game
{
	namespace utils
	{
		std::size_t randomize(std::size_t _num);	 //����������� ��� ���������� ��������

		void sleep(int _seconds);	//��������

		int inverse(int _x);		//�������� ��������� ����������
	}
}