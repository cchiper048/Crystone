#ifndef GAME_H
#define GAME_H

#include "./scene.h"
#include <string>

struct InputClass;
struct SDL_Window;
struct SDL_Renderer;

class Game {
    public:
        Game(const char *title, int width, int height);
        ~Game();
        void changeScene(Scene newScene);
        void Present();
        void Loop();
        short int FPS;
    private:
        SDL_Window *window;
        SDL_Renderer *renderer;
        bool running;
        Scene currectScene;
        InputClass *Input;
};

#endif
