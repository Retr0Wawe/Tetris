#include "Game.hpp"
#include <cstdint>
#include <stdexcept>

using namespace game;

int main()
{
	Figure fi;

	Tetris tetr(fi, 183, 20);

	try {
		tetr.start();
	}
	catch (const std::exception& err) {		//ловим все возможные ошибки
		std::printf("%s", err.what());			//узнаем что за ошибки
	}
}