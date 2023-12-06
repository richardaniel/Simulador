#include "SDL2/SDL.h"
#include <iostream>
#include "Events.hpp"
#include "curl/curl.h"
#include <string>
#include <iostream>


void Events::handleEvents(){
    SDL_Event event;

    SDL_PollEvent(&event);

    if(event.type==SDL_KEYDOWN){
        
    }
   
    
}




    


