#include "Game.hpp"
#include <cstdint>

using namespace game;

int main()
{
	Figure fi;		//обьект фигуры
	Tetris tetr(fi, 183, 20);
	//ициализация основного обьекта, в качестве параметров: обьект фигуры и коды символов для отрисовки 

	tetr.start();		//запуск игры
}