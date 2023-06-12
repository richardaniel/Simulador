#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>


class Entity{

    private:
        float x, y ;
        SDL_Rect currentFrame;
        SDL_Texture* texture;

    public:
        float getX();
        float getY();
        SDL_Texture* getTex();
        SDL_Rect getCurrentFrame();
        Entity(float p_x ,float p_y ,SDL_Texture* p_text );


};
