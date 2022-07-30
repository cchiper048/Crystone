#include "../Qhilius/Qhilius.h"
#include "./Player.h"
#include "./Ball.h"
#include "./Block.h"
#include <vector>

#define TITLE "C-137"
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAX_FPS 60

int main() {
    Game game(TITLE, WINDOW_WIDTH, WINDOW_HEIGHT);
    game.FPS = MAX_FPS;
    Scene scene1;
    Player player;
    Ball ball;

    scene1.addObject(player);
    scene1.addObject(ball);
    std::vector<Block*> blocks;

    for(int i=0; i<5; ++i) {
        for (int j = 0; j < 9; ++j) {
            Block *block = new Block();
            block->rect.x = (float)(8.5 + 85 * j + j*2);
            block->rect.y = (float)(20 + 30*i + i*2);
            block->rect.width = 85;
            block->rect.height = 30;
            scene1.addObject(*block);
            blocks.push_back(block);
        }
    }

    game.changeScene(scene1);
    game.Loop();

    for(auto i: blocks) {
        delete i;
    }

    return 0;
}
