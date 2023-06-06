#include "Spawner.hpp"
#include "Tiempo.hpp"
#include "Func_aux.hpp"
#include "../objetos_dinamicos/ObjetoDinamico.hpp"
#include "../motor/imagen/Atlas.hpp"

#include <iostream>
#include <cstdlib>

Spawner::Spawner(int x, int y,int sw, int sh, SDL_Color c, Pipeline &p)
{
    colordebug=c;
    this->x=x; //pos x
    this->y=y; //pos y
    this->w=w; //ancho del sprite
    this->h=h; //alto del sprite
    this->sw=sw; //ancho mostrar sprite
    this->sh=sh; //alto mostrar sprite
    objetos_activos=0;
    jugador=nullptr;
    delay=3;
    init_tiempo = Tiempo::get_tiempo();
    check=false;
    pipeline = &p;
    velocidad=0;
};

void Spawner::spawn(std::vector<Enemy*> *lista)
{
    
    //random
    srand((unsigned) time(NULL));
    int sx, sy, atk;
    int enemigo = rand()%25;
    
    do
    {
        int posX = rand()%50;
        int posY = rand()%50;
        sx = x + (posX*72);
        sy = y + (posY*72);
    } while (Atlas::get().indiceCuadro(sx/72 , sy/72) != 18);
    
    if(enemigo != 13)
    {
        sprite_path = "assets/sprites/enemigos/enemigo2.png";
        atk = 3;
        v = 90;
        w = 64;
        h = 68;
    }
    else
    {
        sprite_path = "assets/sprites/enemigos/enemigo1.png";
        atk = 8;
        v = 120;
        w = 63;
        h = 84;
    }
    Enemy * nuevo = new Enemy(
    sprite_path,v,sx,sy,w,h,sw,sh,atk,colordebug);
    pipeline->cargar_texturas(nuevo->get_sprite());
    lista->push_back(nuevo);
    objetos_activos++;

};

void Spawner::set_velocidad(int v)
{
    velocidad=v;
};

void Spawner::despawn(std::vector<Enemy*> *lista)
{
    int i=0;
    for(auto &p : *lista)
    {
        if(p->get_vida()<=0)
        {
            delete lista->at(i);
            lista->erase((lista->begin()+i));
            i++;
        }
        i++;
    }

    objetos_activos--;
};


void Spawner::update(std::vector<Enemy*> *lista)
{
    double dt =  Tiempo::get_tiempo() - init_tiempo;

    
    if((int)dt!=0 && ((int)dt)%delay == 0 && check==false && objetos_activos<5)
    {
        
        spawn(lista);
        past_tiempo=dt;
        check=true;
    }

    if((int)dt>past_tiempo)
    {    
        check=false;
    }
};