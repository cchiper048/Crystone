#ifndef GAME_H
#define GAME_H

#include "./helpers/types.h"
#include "./scene.h"

struct InputClass;
struct SDL_Window;
struct SDL_Renderer;

class Game {
    public:
        Game(const char *title, I32 width, I32 height);
        ~Game();
        void changeScene(Scene newScene);
        void Present();
        void Loop();
        U16 FPS;
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        SDL_bool running;
        Scene currectScene;
        InputClass *Input;
};

#endif
