#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Entity.hpp"
#include <iostream>



Entity::Entity(Vector2f p_pos ,SDL_Texture* p_text):pos(p_pos),texture(p_text){

    
   currentFrame.x=0;
   currentFrame.y=0;
   currentFrame.w=32;
   currentFrame.h=32;

}
void Entity::move(const Vector2f& offset) {
    pos.x += offset.x;
    pos.y += offset.y;
}

Vector2f Entity::getPosition(){
    return pos;
}


SDL_Texture* Entity::getTex(){
    return texture;
}

SDL_Rect Entity::getCurrentFrame(){
    return currentFrame; 
}

