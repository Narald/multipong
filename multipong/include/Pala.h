#ifndef PALA_H
#define PALA_H

#include <SDL.h>

typedef enum { DIRECTION_UP = 1, DIRECTION_DOWN = 2, DIRECTION_NONE = 0 } Direcction;

class Pala
{
    public:
        Pala();
        virtual ~Pala();

        //Initialization
        void Init(int player);

        //Update para la IA
        void Update(float deltaTime, Direcction dir);

        //render
        void Render(SDL_Surface* surf);

        SDL_Rect* getRect();
    protected:

    private:
        SDL_Rect rect;
        float speed;
        float delta;
        int player;
};

#endif // PALA_H
