class Ball
{
private:
    int x, y;
    int origx, origy;
    eDir direction;

public:
    Ball(int posx, int posy);
    void reset();
    void change_dir(eDir d);
    void random_dir();
    int get_x();
    int get_y();
    int get_dir();
    void move();
};