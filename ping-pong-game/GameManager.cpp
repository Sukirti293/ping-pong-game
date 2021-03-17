#include "PingPong.h"
#include "Ball.h"
#include "Paddle.h"
#include "GameManager.h"

GameManager::GameManager(int w, int h)
{
    srand(time(NULL));
    quit = false;
    up1 = 'w';
    up2 = 'i';
    down1 = 's';
    down2 = 'k';
    score1 = score2 = 0;
    width = w;
    height = h;
    ball = new Ball(w / 2, h / 2);
    p1 = new Paddle(1, h / 2 - 3);
    p2 = new Paddle(w - 2, h / 2 - 3);
}

GameManager::~GameManager()
{
    delete ball;
    delete p1;
    delete p2;
}

void GameManager::score_up(Paddle* player)
{
    if (player == p1)
    {
        score1 += 1;
    }

    if (player == p2)
    {
        score2 += 1;
    }

    ball->reset();
    p1->reset();
    p2->reset();
}

void GameManager::clear_screen()
{
    COORD cursor_position;
    cursor_position.X = 0;
    cursor_position.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursor_position);
}

void GameManager::draw()
{
    clear_screen();

    for (int i = 0; i < width + 2; i += 1)
        cout << "\xB2";
    cout << endl;

    for (int i = 0; i < height; i += 1)
    {
        for (int j = 0; j < width; j += 1)
        {
            int ball_x = ball->get_x();
            int ball_y = ball->get_y();
            int player1_x = p1->get_x();
            int player2_x = p2->get_x();
            int player1_y = p1->get_y();
            int player2_y = p2->get_y();

            if (j == 0)
                cout << "\xB2";

            if (ball_x == j && ball_y == i)
                cout << "O";
            else if (player1_x == j && player1_y == i)
                cout << "\xDB";
            else if (player1_x == j && player1_y + 1 == i)
                cout << "\xDB";
            else if (player1_x == j && player1_y + 2 == i)
                cout << "\xDB";
            else if (player1_x == j && player1_y + 3 == i)
                cout << "\xDB";
            else if (player2_x == j && player2_y == i)
                cout << "\xDB";
            else if (player2_x == j && player2_y + 1 == i)
                cout << "\xDB";
            else if (player2_x == j && player2_y + 2 == i)
                cout << "\xDB";
            else if (player2_x == j && player2_y + 3 == i)
                cout << "\xDB";
            else
                cout << " ";

            if (j == width - 1)
                cout << "\xB2";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i += 1)
        cout << "\xB2";
    cout << endl;
    cout << "Score 1:" << score1 << endl
        << "Score 2:" << score2 << endl;
}

void GameManager::input()
{
    ball->move();
    int player1_y = p1->get_y();
    int player2_y = p2->get_y();

    if (_kbhit())
    {
        char current = _getch();
        if (current == up1)
            if (player1_y > 0)
                p1->move_up();

        if (current == up2)
            if (player2_y > 0)
                p2->move_up();

        if (current == down1)
            if (player1_y + 4 < height)
                p1->move_down();

        if (current == down2)
            if (player2_y + 4 < height)
                p2->move_down();

        if (ball->get_dir() == b_stop)
            ball->random_dir();

        if (current == 'q')
            quit = true;
    }
}

void GameManager::logic()
{
    int ball_x = ball->get_x();
    int ball_y = ball->get_y();
    int player1_x = p1->get_x();
    int player1_y = p1->get_y();
    int player2_x = p2->get_x();
    int player2_y = p2->get_y();

    for (int i = 0; i < 4; i += 1)
    {
        if (ball_x == player1_x + 1)
            if (ball_y == player1_y + i)
                ball->change_dir((eDir)(rand() % 3 + 4));
    }

    for (int i = 0; i < 4; i += 1)
    {
        if (ball_x == player2_x - 1)
            if (ball_y == player2_y + i)
                ball->change_dir((eDir)(rand() % 3 + 1));
    }

    if (ball_y == height - 1)
        ball->change_dir(ball->get_dir() == b_downright ? b_upright : b_upleft);

    if (ball_y == 0)
        ball->change_dir(ball->get_dir() == b_upright ? b_downright : b_downleft);

    if (ball_x == 0)
        score_up(p2);

    if (ball_x == width)
        score_up(p1);
}

void GameManager::run()
{
    while (!quit)
    {
        draw();
        input();
        logic();
    }
}
