#include <SDL.h>
#include <stdio.h>
#include <iostream>
#include "Red.h"
#include "Game.h"
#include "Constants.h"

int main(int argc, char** argv){
    if (SDL_Init(SDL_INIT_VIDEO) != 0){
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    char TITLE[1024];

    bool somosServidor = false;

    #ifdef SERVIDOR
        sprintf(TITLE,"Multipong - Servidor");
        somosServidor = true;
        std::cout << "SOMOS SERVIDOR" << SDL_GetError() << std::endl;
    #else
        sprintf(TITLE,"Multipong - Cliente");
        std::cout << "SOMOS CLIENTE" << SDL_GetError() << std::endl;
    #endif // SERVIDOR

    SDL_Window *win = SDL_CreateWindow(TITLE, 100, 100, WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_SHOWN);
    if (win == nullptr){
        std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return -1;
    }else{
        std::cout << "Ventana Inicializada" << std::endl;
    }

    //Creamos clase que se encargará del juego
    Game game;

    //si somos servidor
    if(somosServidor){
        game.iniciaServidorJugador(win, 2, 9999);
    }else{
        game.iniciaCliente(win,"localhost",9999);
    }


    SDL_DestroyWindow(win);
    SDL_Quit();

    return 0;
}
