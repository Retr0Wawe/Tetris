#include "Game.hpp"
#include <cstdint>
#include <stdexcept>

int main()
{
	try {

	}
	catch (const std::runtime_error& err) {		//����� ��� ��������� ������
		std::printf("%s", err.what());			//������ ��� �� ������
	}
}