#include "../engine/engine_include.h"
#include "./Player.h"
#include "./Ball.h"
#include "./Block.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAX_FPS 60

int main(void) {
    Game game("C-137", WINDOW_WIDTH, WINDOW_HEIGHT);
    game.FPS = MAX_FPS;
    Scene scene1;
    Player player;
    Ball ball;

    scene1.addObject(player);
    scene1.addObject(ball);

    for(int i=0; i<20; ++i) {
        Block* block = new Block();
        block->transform.localPosition.x = 20*i;
        block->transform.localPosition.y = 300;
        block->transform.localSize.x = 20;
        block->transform.localSize.y = 20;
        scene1.addObject(* block);
    }

    game.changeScene(scene1);
    game.Loop();

    return 0;
}
