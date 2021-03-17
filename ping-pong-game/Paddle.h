class Paddle
{
private:
    int x, y;
    int origx, origy;

public:
    Paddle();
    Paddle(int posx, int posy);
    void reset();
    int get_x();
    int get_y();
    void move_up();
    void move_down();
};