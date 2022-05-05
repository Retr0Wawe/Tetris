#pragma once

#include <array>
#include <cstdint>

namespace game
{
	//��� ���������� ��������� �� ����� ���������� ����� �� �������� runtime'�(�� ���� ������� ������)
	
	inline int py, px = 0;		//���������� - ���������� ������������ ������� ������������ ������ �� x, y

	constexpr int figure_counts = 4;	//���������� ����� �������
	constexpr int figure_size = 4;

	constexpr std::size_t field_x = 20;		//���������� �������� ���������� ����
	constexpr std::size_t field_y = 20;

	template<typename _T, std::size_t _X, std::size_t _Y = _X>	//��������� ��� ���������� ������� � ���������� �����������
	using double_array = std::array<std::array<_T, _X>, _Y>;	
	//���� ��� �� ����� ������ � ������� ���������, �� ������ �������� �������� _X �������� _Y(�������� �� ���������)

	enum class eKeys : unsigned int		//���������� ������������ ������
	{
		KEY_UP = 72, KEY_DOWN = 80, KEY_LEFT = 75, KEY_RIGHT = 77,
		KEY_SPACE = 32, KEY_ESC = 27, KEY_ENTER = 13
	};
}