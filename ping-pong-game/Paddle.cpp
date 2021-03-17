#include "Paddle.h"

Paddle::Paddle()
{
    x = y = 0;
}

Paddle::Paddle(int posx, int posy) : Paddle::Paddle()
{
    origx = posx;
    origy = posy;
    x = posx;
    y = posy;
}

void Paddle::reset()
{
    x = origx;
    y = origy;
}

int Paddle::get_x()
{
    return x;
}

int Paddle::get_y()
{
    return y;
}

void Paddle::move_up()
{
    y--;
}

void Paddle::move_down()
{
    y++;
}