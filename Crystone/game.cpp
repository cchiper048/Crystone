#include <SDL2/SDL.h>
#include <iostream>
#include "./game.h"
#include "./input.h"
#include "./helpers/algorithm.h"

Game::Game(const char *title, int width, int height) {
    SDL_Init(SDL_INIT_VIDEO | SDL_RENDERER_PRESENTVSYNC);

    this->window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    if (this->window == nullptr) std::cout << "ERROR : Cannot instantiate SDL_Window \n";

    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (this->renderer == nullptr) std::cout << "ERROR : Cannot instantiate SDL_Renderer \n";

    this->FPS = 60;
    this->running = true;
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
    const float frameDelay = 1000 / FPS;
    int frameStart, frameTime;

    for(const auto obj: this->currectScene.objects) {
        obj->Input = this->Input;
        obj->Start();
    }

    while(this->running) {
        frameStart = SDL_GetTicks();
        // Window Events
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_QUIT: // Close window
                this->running = false;
                break;
            }
            Input->Update(event);
        }

        // Update all Objects in currcet scene
        for(size_t i=0; i < currectScene.objects.size(); ++i) {
            currectScene.objects[i]->Update();

            if(currectScene.objects[i]->BoxCollider2D) { // Check if BoxColliding is Enabled
                for(size_t j=i+1; j < currectScene.objects.size(); ++j) {
                    if(AABB_Collision(*currectScene.objects[i], *currectScene.objects[j]) ) {
                        currectScene.objects[i]->BoxColliding(*currectScene.objects[j]);
                        currectScene.objects[j]->BoxColliding(*currectScene.objects[i]);
                    }
                }
            }
            
            if(currectScene.objects[i]->renderObject) {
                SDL_SetRenderDrawColor(this->renderer, 255, 255, 255, 1);
                SDL_Rect r;
                r.x = currectScene.objects[i]->transform.localPosition.x;
                r.y = currectScene.objects[i]->transform.localPosition.y;
                r.w = currectScene.objects[i]->transform.localSize.x;
                r.h = currectScene.objects[i]->transform.localSize.y;
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