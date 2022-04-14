#include "Game.hpp"
#include <cstdint>
#include <stdexcept>

int main()
{
	try {

	}
	catch (const std::runtime_error& err) {		//ловим все возможные ошибки
		std::printf("%s", err.what());			//узнаем что за ошибки
	}
}