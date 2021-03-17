#include "PingPong.h"
#include "Ball.h"
#include "Paddle.h"
#include "GameManager.h"

int main() {
    GameManager c(40, 20);
    c.run();

    return 0;
}