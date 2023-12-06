#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "RenderWindow.hpp"
#include <iostream>

#include "Entity.hpp"
#include <SDL2/SDL_ttf.h>
#include <string>


using namespace std;

RenderWindow::RenderWindow(const char* p_title , int p_w , int p_h):window(NULL),renderer(NULL){
    window=SDL_CreateWindow(p_title,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,p_w,p_h,SDL_WINDOW_SHOWN);


    if(window==NULL){
        cout<<"Error al crear la ventana"<<SDL_GetError()<<endl;
    }

    renderer=SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED && SDL_RENDERER_PRESENTVSYNC);
}
SDL_Texture* RenderWindow::loadTexture(const char* p_filePath){
    
    SDL_Texture* texture =NULL;
    texture=IMG_LoadTexture(renderer , p_filePath);

    if(texture==NULL){
        cout<<"Error al cargar la textura"<<SDL_GetError()<<endl;

    }

    return texture;
}



int RenderWindow::getRefreshRate(){
    int displayIndex = SDL_GetWindowDisplayIndex(window);
    SDL_DisplayMode mode;

    SDL_GetDisplayMode(displayIndex ,0,&mode);

    return mode.refresh_rate;
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
    dst.x=p_entity.getPos().x * 4;
    dst.y=p_entity.getPos().y * 4;
    dst.w=p_entity.getCurrentFrame().w * 4;
    dst.h=p_entity.getCurrentFrame().h * 4;

    SDL_RenderCopy(renderer,p_entity.getTex(),&src,&dst);

}

void RenderWindow::renderObjects(SDL_Texture* texture){
    SDL_RenderCopy(renderer,texture,NULL,NULL);
}


void RenderWindow::display(){
    SDL_RenderPresent(renderer);
}

SDL_Texture* RenderWindow::createLabelTexture(TTF_Font* font, SDL_Color textColor, int x, int y, const std::string& text) {
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

SDL_Texture* RenderWindow::createTextBoxTexture(TTF_Font* font, SDL_Color textColor, int x, int y, int width, int height, const std::string& text) {
    SDL_Surface* surface = TTF_RenderText_Blended(font, text.c_str(), textColor);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}



