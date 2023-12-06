#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Math.hpp"

class Entity{

    private:
        Vector2f pos;
        SDL_Rect currentFrame;
        SDL_Texture* texture;

    public:
        Entity(Vector2f ,SDL_Texture* p_text);
        Vector2f& getPos(){
            return pos;
        }
        SDL_Texture* getTex();
        SDL_Rect getCurrentFrame();
        Entity(float p_x ,float p_y ,SDL_Texture* p_text );
        void move(const Vector2f& offset);
        Vector2f getPosition();


};
