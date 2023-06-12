#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "RenderWindow.hpp"
#include <iostream>

#include "Entity.hpp"


using namespace std;

RenderWindow::RenderWindow(const char* p_title , int p_w , int p_h):window(NULL),renderer(NULL){
    window=SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,p_w,p_h,SDL_WINDOW_SHOWN);


    if(window==NULL){
        cout<<"Error al crear la ventana"<<SDL_GetError()<<endl;
    }

    renderer=SDL_CreateRenderer(window,-1,0);
}
SDL_Texture* RenderWindow::loadTexture(const char* p_filePath){
    
    SDL_Texture* texture =NULL;
    texture=IMG_LoadTexture(renderer , p_filePath);

    if(texture==NULL){
        cout<<"Error al cargar la textura"<<SDL_GetError()<<endl;

    }

    return texture;
}


void RenderWindow::CleanUp(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}


void RenderWindow::clear(){
    SDL_RenderClear(renderer);
}

void RenderWindow::render(Entity& p_entity){

    SDL_Rect src;
    src.x=p_entity.getCurrentFrame().x;
    src.y=p_entity.getCurrentFrame().y;
    src.w=p_entity.getCurrentFrame().w;
    src.h=p_entity.getCurrentFrame().h;

    SDL_Rect dst;
    dst.x=p_entity.getX() * 4;
    dst.y=p_entity.getY() * 4;
    dst.w=p_entity.getCurrentFrame().w * 4;
    dst.h=p_entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(renderer,p_entity.getTex(),&src,&dst);

}


void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}


