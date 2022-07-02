#include <SDL2/SDL.h>
#include <iostream>
#include "./game.h"
#include "./input.h"


Game::Game(const char *title, I32 width, I32 height) {
    SDL_Init(SDL_INIT_VIDEO | SDL_RENDERER_PRESENTVSYNC);

    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, (I32)width, (I32)height, SDL_WINDOW_SHOWN);
    if (this->window == nullptr) std::cout << "ERROR : Cannot instantiate SDL_Window \n";

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == nullptr) std::cout << "ERROR : Cannot instantiate SDL_Renderer \n";

    this->FPS = 60;
    this->running = SDL_TRUE;
    this->currectScene = Scene();
    this->Input = new InputClass();
}

Game::~Game() {
    SDL_DestroyRenderer(this->renderer);
    SDL_DestroyWindow(this->window);

    SDL_Quit();
}

void Game::Present() {
    SDL_RenderPresent(this->renderer);
    SDL_SetRenderDrawColor(this->renderer, 98, 0, 238, 1);
    SDL_RenderClear(this->renderer);
}

void Game::changeScene(Scene newScene) {
    this->currectScene = newScene;
}

void Game::Loop() {
    SDL_Event event;
    const F32 frameDelay = 1000 / FPS;
    U32 frameStart, frameTime;

    for(const auto obj: this->currectScene.objects) {
        obj->Input = this->Input;
    }

    while(this->running) {
        frameStart = SDL_GetTicks();
        // Window Events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT: // Close window
                this->running = SDL_FALSE;
                break;
            }
            Input->Update(event);
        }

        // Update all Objects in currcet scene
        for(const auto obj: this->currectScene.objects) {
            obj->Update();
            
            if(obj->renderObject) {
                SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 1);
                SDL_Rect r;
                r.x = obj->position.x;
                r.y = obj->position.y;
                r.w = obj->size.x;
                r.h = obj->size.y;
                SDL_RenderFillRect(this->renderer, &r);
            }
        }
        // Draw
        Game::Present();
    
        frameTime = SDL_GetTicks() - frameStart;
        if(frameDelay > frameTime) {
            SDL_Delay(frameDelay - frameTime);
        }
    }
}