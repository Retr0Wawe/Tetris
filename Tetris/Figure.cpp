#include "Figure.hpp"
#include "Game.hpp"
#include "Utils.hpp"

namespace game
{
	void Figure::create() 
	{
        for (int i = 0; i < figure_size; i++) {
            for (int j = 0; j < figure_size; j++) {
                figure_field[j][i] = figurs_sample[next_map][j][i];
            }
        }

        py = 0; px = field_x / 2;

        next_map = utils::randomize(figure_counts - 1);

        utils::cursor_to_xy(field_x + 1, 2);
        Tetris::print_next_figure();
	}

    void Figure::rotate()
    {
        bool _map[figure_size][figure_size];

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
        if (_x < 0) {
            return false;
        }

        for (int i = 0; i < figure_size; i++) {
            for (int j = 0; j < figure_size; j++) {
                if (figure_field[j][i]) {
                    if ((j + _x >= field_x) || (i + _y >= field_y)) {
                        return false;
                    }

                    if (_tet.field[j + _x][i + _y]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
}