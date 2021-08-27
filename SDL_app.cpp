#include "SDL_app.h"

SDL_App::SDL_app::SDL_app(Uint32 init_flags,
                 Uint32 window_flags,
                 Uint32 renderer_flags,
                 const char* win_title,
                 int x, int y,
                 int w, int h) {

    m_main_window = NULL;
    m_main_renderer = NULL;

    if(SDL_Init(init_flags) < 0){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        throw SDL_Init_Exception(SDL_GetError());
    }

    m_main_window = SDL_CreateWindow(win_title, x, y, w, h, window_flags);
    if(!m_main_window){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        throw SDL_Window_Exception(SDL_GetError());
    }

    m_main_renderer = SDL_CreateRenderer(m_main_window, -1, renderer_flags);
    if(!m_main_renderer){
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "[DEBUG] > %s", SDL_GetError());
        throw SDL_Renderer_Exception(SDL_GetError());
    }



}

void SDL_App::SDL_app::run() {
    SDL_bool running = SDL_TRUE;
    SDL_RenderClear(m_main_renderer);

    while (running == SDL_TRUE){
        running = events();
        draw();
        SDL_Delay(1);
        render();

    }

}

void SDL_App::SDL_app::quit() {
    destroy();

    SDL_DestroyRenderer(m_main_renderer);
    SDL_DestroyWindow(m_main_window);
    SDL_Quit();

}

void SDL_App::SDL_app::getWindowSize(int* w, int* h){
    SDL_GetWindowSize(m_main_window, w, h);
}

SDL_Renderer* SDL_App::SDL_app::getMainRenderer(){
    return m_main_renderer;
}
