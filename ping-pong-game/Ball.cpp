#include "PingPong.h"
#include "Ball.h"

Ball::Ball(int posx, int posy)
{
    origx = posx;
    origy = posy;
    x = posx;
    y = posy;
    direction = b_stop;
}

void Ball::reset()
{
    x = origx;
    y = origy;
    direction = b_stop;
}

void Ball::change_dir(eDir d)
{
    direction = d;
}

void Ball::random_dir()
{
    direction = (eDir)((rand() % 6) + 1);
}

int Ball::get_x()
{
    return x;
}

int Ball::get_y()
{
    return y;
}

int Ball::get_dir()
{
    return direction;
}

void Ball::move()
{
    switch (direction)
    {
    case b_stop:
        break;
    case b_left:
        x--;
        break;
    case b_right:
        x++;
        break;
    case b_upleft:
        x--;
        y--;
        break;
    case b_downleft:
        x--;
        y++;
        break;
    case b_upright:
        x++;
        y--;
        break;
    case b_downright:
        x++;
        y++;
        break;
    default:
        break;
    }
}