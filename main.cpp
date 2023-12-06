#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <unordered_map>
#include <SDL2/SDL_ttf.h>
#include <SFML/Audio.hpp>

#include "RenderWindow.hpp"
#include "Entity.hpp"
#include "Utils.hpp"
#include "Events.hpp"


void menu();
void submenu();

int n_autos ,t_autos;
using namespace std;



void menu(){
    cout<<"Bienvenido al simulador de trafico"<<endl;
    cout<<"1. Iniciar simulacion"<<endl;
    cout<<"2. Salir"<<endl;
    cout<<"Ingrese una opcion: ";
    int opcion;
    cin>>opcion;
    switch(opcion){
        case 1:
            cout<<"Iniciando simulacion..."<<endl;
            submenu();
            break;
        case 2:
            cout<<"Saliendo..."<<endl;
            break;
        default:
            cout<<"Opcion invalida"<<endl;
            break;
    }
}

void submenu(){
    int n_generadores;
    cout<<"Ingrese cantidad de generadores: ";
    cin>>n_generadores;
    cout<<endl;
    int n_consumidores;
    cout<<"Ingrese cantidad de consumidores: ";
    cin>>n_consumidores;
    cout<<endl;
    
    cout<<"Generadores: "<<n_generadores<<endl;
    cout<<"Consumidores: "<<n_consumidores<<endl;
  

    cout<<"Ingrese la cantidad de autos a generar: ";
    
    cin>>n_autos;
    cout<<endl;
    cout<<"Ingrese el tiempo en segundos para generar los autos: ";
    cin>>t_autos;
    cout<<endl;
    cout<<"Generaremos: "<<n_autos<<" autos cada "<<t_autos<<" segundos"<<endl;

    cout<<"Ingrese la cantidad de autos a desalojar: ";
    int n_autos2;
    cin>>n_autos2;
    cout<<endl;
    cout<<"Ingrese el tiempo en segundos para desalojar los autos: ";
    int t_autos2;
    cin>>t_autos2;
    cout<<endl;
    cout<<"Desalojaremos: "<<n_autos2<<" autos cada "<<t_autos2<<" segundos"<<endl;


    cout<<"Ingrese tiempo de muestra en segundos: ";
    float t_muestra;
    cin>>t_muestra;
    cout<<endl;


    int c_muestra_generador=((t_muestra/t_autos)*n_autos)*n_generadores;
    int c_muestra_consumidor=((t_muestra/t_autos2)*n_autos2)*n_consumidores;
    float resultado=c_muestra_generador-c_muestra_consumidor;

    if(resultado<=0){
        cout<<"Hay trafico fluido"<<endl;
    }
    else{
        
        cout<<"por cada "<<t_muestra<<" segundos, se generaran "<<c_muestra_generador<<" autos y se desalojaran "<<c_muestra_consumidor<<" autos"<<endl;
    cout<<"Lo que llevara a tener un total de "<<resultado<<" autos en aglomeracion y se producira congestionamiento"<<endl;

    cout<<"Un motor consume en una hora, alrededor de entre 1.5 y 2 litros de gasolina "<<endl;
    cout<<"Un motor de 4 cilindros consume entre 3.5 y 4 litros de gasolina por hora" <<endl;
    float litros_consumidos_segundo=(resultado*(2.00/3600.00)*t_muestra)/3600;
    cout<<"En "<<t_muestra<<" segundos, se consumiran "<<litros_consumidos_segundo*t_muestra<<" litros de gasolina"<<endl;
    float litros_galones=(litros_consumidos_segundo*t_muestra)/3.785;
    cout<<"En "<<t_muestra<<" segundos, se consumiran "<<litros_galones<<" galones de gasolina"<<endl;
    cout<<"Cada litro de gasolina en combustion equivale a 3 kg de CO2"<<endl;
    float kg_co2=(litros_consumidos_segundo*t_muestra)/3;
    cout<<"En "<<t_muestra<<" segundos, se emitiran "<<kg_co2<<" kg de CO2"<<endl;
    cout<<"Cada galon de gasolina equivale a 8.9 kg de CO2"<<endl;
    cout<<"un arbol absorbe 21.77 kg de CO2"<<endl;
    float arboles=kg_co2/21.77;
    cout<<"un arbol absorbe 21.77 kg de CO2"<<endl;
    cout<<"Se necesitan "<<arboles<<" arboles para compensar la emision de CO2"<<endl;
    cout<<"Siendo esto un simulador de trafico que podemos hacer para mejorar cada punto"<<endl;
    cout<<"Tomando en consideracion que lo generadores y consumidores son calles"<<endl;
    cout<<"¿Que hacer para mejorar el trafico?"<<endl;

    system("python chatGPT.py");
    }
    
    



    
   

}

int main(int argc ,char* args[]){


    menu();

   if(SDL_Init(SDL_INIT_VIDEO)<0){
        cout<<"Error: "<<SDL_GetError()<<endl;
        return 1;
   }
    
    
  
  if(TTF_Init()<0){
        cout << "TTF_Init ha fallado. Error: " << TTF_GetError() << endl;
        return 1;
    }

    if(IMG_Init(IMG_INIT_PNG)<0){
        cout<<"IMG_init ha fallado .Error :"<<IMG_GetError()<<endl;
        return 1;
    }
        

    RenderWindow window("SIMULADOR v1.0",1280,720);

    
    int lastTime=SDL_GetTicks();
    SDL_Texture*  Texture = window.loadTexture("resources/gfx/bg.png");
  


    unordered_map <string,SDL_Texture*> HashTable;

    HashTable["carro1"]=window.loadTexture("resources/gfx/carros/carro14.png");
    HashTable["Fondo"]=window.loadTexture("resources/gfx/fondo.jpg");
    HashTable["Semaforo"]=window.loadTexture("resources/gfx/semafaros/semafaro1.png");


    
   

    int x=30;
    vector <Entity> entities = {Entity(Vector2f(0,150),Texture),
                                Entity(Vector2f(x,150),Texture),
                                Entity(Vector2f(x*2,150),Texture),
                                Entity(Vector2f(x*3,150),Texture),
                                Entity(Vector2f(x*4,150),Texture),
                                Entity(Vector2f(x*5,150),Texture),
                                Entity(Vector2f(x*6,150),Texture),
                                Entity(Vector2f(x*7,150),Texture),
                                Entity(Vector2f(x*8,150),Texture),
                                Entity(Vector2f(x*9,150),Texture),
                                Entity(Vector2f(x*10,150),Texture)};


vector <Entity> entities2 = {};                       
   for (int i = 0; i < n_autos; i++) {
        Entity car(Vector2f(x-10 * i, 132), HashTable["carro1"]);
        entities2.push_back(car);
    }
    

   /* TTF_Font* font = TTF_OpenFont("resources/dev/segoeui.ttf",8);
    SDL_Color textColor = { 0, 0, 0 }; // Blanco

    // Crear la textura del label
    HashTable["label"]=window.createLabelTexture(font, textColor, 5, 5, "¡Hola, mundo!");*/

  
    bool Running=true;

    SDL_Event event;

    const int FPS=60;
    const int Frame_delay=1000/FPS;
    int car_position=20;
    int timeElapsed = 0;
    int car_index=0;
    
    while(Running){

     
        
       int startTime=SDL_GetTicks();
       int deltaTime = startTime-lastTime;
       lastTime=startTime;
     

       timeElapsed += deltaTime;

    if (timeElapsed >= 10) {
        car_position += 5;
        timeElapsed = 0;
       
    }
    // cout <<car_position<< endl;---->imprime la posicion del auto
       

       if(deltaTime>=10){
                
               //entities2.back().move(Vector2f(1,0));----->un solo auto en bucle infinito
                

           /*for (auto it = entities2.begin(); it != entities2.end(); ) {
            Entity& car = *it;
            car.move(Vector2f(1, 0));
          
            

            // Verificar si el carro ha alcanzado la pantalla
            if (car_position + 32 >= 768) {
                car_position=0;
                car.move(Vector2f(0, 132));
            }
        }*/ 


    }
    Entity& current_car = entities2[car_index];
    int target_position=780-x*car_index;
    int current_position=car_position;
    if(current_position<target_position){
        current_car.move(Vector2f(1,0));
    }

    if(current_position>=target_position){
        car_index++;
        car_position=0;
        if(car_index>=entities2.size()){
            car_index=0;
        }
    }

            lastTime = startTime;
       
       
            while(SDL_PollEvent(&event)){

            if(event.type==SDL_QUIT)
                Running = false;
            } 
          
        window.clear();

        //Renderizamos el fondo de pantalla
      
        window.renderObjects(HashTable["Fondo"]);



        //Renderizamos el objeto consumidor
        Entity consumidor={Vector2f(200,115),HashTable["Semaforo"]};
        window.render(consumidor);

       /* Entity label={Vector2f(5,5),HashTable["label"]};
        window.render(label);*/

    
       for(Entity& e : entities){
            window.render(e);
        }
        
         for(Entity& c: entities2){
            window.render(c);


    
        }
            window.display();   
        Uint32 frameTime =SDL_GetTicks()-startTime;
        if(frameTime<Frame_delay){
            SDL_Delay(Frame_delay-frameTime);
        }
        if (entities2.empty()) {
       
    }

}
   

    window.CleanUp();
    IMG_Quit();
    SDL_Quit();

    
    return 0;

   

}