#ifndef SDL_APP_SDL_APP_H
#define SDL_APP_SDL_APP_H

#include <SDL2/SDL.h>
#include <stdexcept>
#include <string>
#include <cstdlib>
namespace SDL_App{

    class SDL_app{

    private:
        SDL_Window* m_main_window;
        SDL_Renderer* m_main_renderer;

        virtual void destroy() = 0;

        virtual SDL_bool events() = 0;
        virtual void draw() = 0;
        virtual void render() = 0;

    public :
        SDL_app(Uint32 init_flags,
                Uint32 window_flags,
                Uint32 renderer_flags,
                const char* win_title,
                int x, int y,
                int w, int h);

        virtual void run();
        virtual void quit();

        void getWindowSize(int* w, int* h);
        SDL_Renderer* getMainRenderer();

        virtual ~SDL_app(){};


    };




    /*Exceptions*/

    class SDL_Init_Exception : public std::runtime_error{

    public:
        SDL_Init_Exception(const char *s)  :  std::runtime_error(s){

        }

        const char* what() const throw(){
            return "SDL_Init failed";
        }
    };
    class SDL_Window_Exception : public std::runtime_error{

    public:
        SDL_Window_Exception(const char *s)  :  std::runtime_error(s){

        }

        const char* what() const throw(){
            return "SDL_CreateWindow failed";
        }
    };
    class SDL_Renderer_Exception : public std::runtime_error{

    public:
        SDL_Renderer_Exception(const char *s)  :  std::runtime_error(s){

        }

        const char* what() const throw(){
            return "SDL_Renderer failed";
        }
    };
}


#endif //SDL_APP_SDL_APP_H
