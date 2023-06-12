#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include <iostream>


Entity::Entity(float p_x,float p_y ,SDL_Texture* p_text):x(p_x) , y(p_y) ,texture(p_text){

   currentFrame.x=0;
   currentFrame.y=0;
   currentFrame.w=32;
   currentFrame.h=32;

}

float Entity::getX(){
    return x;
}

float Entity::getY(){
    return y;
}


SDL_Texture* Entity::getTex(){
    return texture;
}

SDL_Rect Entity::getCurrentFrame(){
    return currentFrame; 
}

