#include "Figure.hpp"
#include "Game.hpp"
#include "Utils.hpp"

namespace game
{
	void Figure::create() 
	{
        for (int i = 0; i < figure_size; i++) {         //отрисовка поля
            for (int j = 0; j < figure_size; j++) {
                figure_field[j][i] = figurs_sample[next_figure][j][i];
            }
        }

        py = 0; px = field_x / 2;   //отрисовка фигуры по середине поля(по x координате)

        next_figure = utils::randomize(figure_counts - 1);     //рандомный выбор фигуры
        Tetris::print_next_figure();    //напечатывание слудющей фигуры
	}

    void Figure::rotate()
    {
        int _map[figure_size][figure_size];
        int sx = figure_size, sy = figure_size;

        for (int i = 0; i < figure_size; i++) {     
            for (int j = 0; j < figure_size; j++) {
                _map[j][i] = figure_field[j][i];
                if (figure_field[j][i]) {
                    if (i < sx) {
                        sx = i;
                    }
                    if (utils::inverse(j) < sy) {
                        sy = utils::inverse(j);
                    }
                }
            }
        }

        for (int i = 0; i < figure_size; i++) {
            for (int j = 0; j < figure_size; j++) {
                if (_map[utils::inverse(i)][j]) {
                    figure_field[j - sx][i - sy] = 1;
                }
            }
        }
        if (get_move(*this, px, py)) {
            for (int i = 0; i < figure_size; i++) {
                for (int j = 0; j < figure_size; j++) {
                    figure_field[j][i] = _map[j][i];
                }
            }
        }
    }

    bool Figure::get_move(const Tetris& _tet, int _x, int _y)
    {
        if (_x < 0) {	// если x пустой, то возвращаем false 
            return false;		
        }

        for (int i = 0; i < figure_size; i++) {		
            for (int j = 0; j < figure_size; j++) {
                if (figure_field[j][i]) {		
                    if ((j + _x >= field_x) || (i + _y >= field_y)) {	 
                        return false;	//проверяем не выходят ли значения за пределы массива
                    }

                    if (_tet.field[j + _x][i + _y]) {	//проверяем не равны ли значения нулю
                        return false;
                    }
                }
            }
        }
        return true;
    }
}