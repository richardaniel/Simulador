#pragma once
#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include <SDL2/SDL_ttf.h>
#include <string>

#include "Entity.hpp"

class RenderWindow{

    public:
        RenderWindow(const char* p_title ,int p_w ,int p_h);
        SDL_Texture* loadTexture(const char* p_filePath);
        
        int getRefreshRate();
        void clear();
        void render(Entity& p_entity);
        void renderObjects(SDL_Texture* texture);
        void display();
        void CleanUp();
       

        SDL_Texture* createLabelTexture(TTF_Font* font, SDL_Color textColor, int x, int y, const std::string& text);
        SDL_Texture* createTextBoxTexture(TTF_Font* font, SDL_Color textColor, int x, int y, int width, int height, const std::string& text);

        SDL_Renderer* getRenderer() const {
        return renderer;
    }
        
      

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;

    

};