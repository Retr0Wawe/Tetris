#include "Game.hpp"
#include <cstdint>
#include <stdexcept>

using namespace game;

int main()
{
	Figure fi;		//обьект фигуры

	Tetris tetr(fi, 183, 20);		
			//ициализация основного обьекта, в качестве параметров: обьект фигуры и коды символов для отрисовки 

	try {
		tetr.start();		//запуск игры
	}
	catch (const std::exception& err) {		//ловим все возможные ошибки
		std::printf("%s", err.what());			//узнаем что за ошибки
	}
}