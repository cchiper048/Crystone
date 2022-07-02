#include "../engine/engine_include.h"
#include "./Player.h"
#include "./Block.h"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define MAX_FPS 60

I32 main(U0) {
    Game game("C-137", WINDOW_WIDTH, WINDOW_HEIGHT);
    game.FPS = MAX_FPS;
    Scene scene1;
    Player player;

    scene1.addObject(player);

    for(I32 i=0; i<20; ++i) {
        Block* block = new Block();
        block->position.x = 20*i;
        block->position.y = 500;
        block->size.x = 20;
        block->size.y = 20;
        scene1.addObject(* block);
    }

    game.changeScene(scene1);
    game.Loop();

    return 0;
}
