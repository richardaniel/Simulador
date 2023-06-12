#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>



#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Stack.hpp"


using namespace std;



int main(int argc ,char* args[]){

   if(SDL_Init(SDL_INIT_VIDEO)<0){
        cout<<"Error: "<<SDL_GetError()<<endl;
        return 1;
   }
    

    

    if(IMG_Init(IMG_INIT_PNG)<0){
        cout<<"IMG_init ha fallado .Error :"<<IMG_GetError()<<endl;
        return 1;
    }
        

    RenderWindow window("SIMULADOR v1.0",1280,720);

    SDL_Texture*  Texture = window.loadTexture("resources/gfx/bg.png");

    int y=0;

    MyStack <Entity> entities;

    entities.push(Entity(210,y,Texture));

                        
    bool Running=true;

    SDL_Event event;

    while(Running){
        while(SDL_PollEvent(&event)){

            if(event.type==SDL_QUIT)
                Running = false;
        }

        window.clear();

       while(!entities.empty()){
            Entity e = entities.peek();
            entities.pop();
            window.render(e);

        }

                     

  
        window.display();
    }

    window.CleanUp();
    IMG_Quit();
    SDL_Quit();

    
    return 0;

   

}