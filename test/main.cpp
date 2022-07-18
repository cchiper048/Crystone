#include "../Crystone/Crystone.h"
#include "./Player.h"
#include "./Ball.h"
#include "./Block.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAX_FPS 60

int main() {
    Game game("C-137", WINDOW_WIDTH, WINDOW_HEIGHT);
    game.FPS = MAX_FPS;
    Scene scene1;
    Player player;
    Ball ball;

    scene1.addObject(player);
    scene1.addObject(ball);

    for(int i=0; i<5; ++i) {
        for (int j = 0; j < 9; ++j) {
            Block *block = new Block();
            block->transform.localPosition.x = (float)(8.5 + 85 * j + j*2);
            block->transform.localPosition.y = (float)(20 + 30*i + i*2);
            block->transform.localSize.x = 85;
            block->transform.localSize.y = 30;
            scene1.addObject(*block);
        }
    }

    game.changeScene(scene1);
    game.Loop();

    return 0;
}
