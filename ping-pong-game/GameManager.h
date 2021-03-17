class GameManager
{
private:
    int width, height, score1, score2;
    bool quit;
    char up1, up2, down1, down2;
    Ball* ball;
    Paddle* p1;
    Paddle* p2;

public:
    GameManager(int w, int h);
    ~GameManager();
    void score_up(Paddle* player);
    void clear_screen();
    void draw();
    void input();
    void logic();
    void run();
};
